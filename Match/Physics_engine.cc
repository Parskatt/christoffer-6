//Physics engine cc

#include "Physics_engine.h"
#include <vector>


void Physics_engine::gravity(Player & p1, Player & p2)
{
  p1.get_curr_character().set_y_speed(p1.get_curr_character().get_y_speed() + 1);
  p2.get_curr_character().set_y_speed(p2.get_curr_character().get_y_speed() + 1);
}

int Physics_engine::square_super_collision(Object const & o1, Object const & o2)
  {
    int o1_llo{o2.get_limits().left - o1.get_limits().left};
    int o1_uao{o2.get_limits().upper - o1.get_limits().upper};
    if ((cordinate_between(o1_llo,o2.get_size().width,-o2.get_size().width)) &&
      (cordinate_between(o1_uao,o2.get_size().height,-o2.get_size().height)))
      {
        if (o1_llo > 0)
        {
          if (o1_uao > 0)
          {
            if (o1_llo > o1_uao)
            {
              return 1;
            }
            else
            {
              return 2;
            }
          }
          else
          {
            if (o1_llo > (0-o1_uao))
            {
              return 1;
            }
            else
            {
              return 4;
            }
          }
        }
        else
        {
          if (o1_uao > 0)
          {
            if ((0-o1_llo) > o1_uao)
            {
              return 3;
            }
            else
            {
              return 2;
            }
          }
          else
          {
            if ((0-o1_llo) > (0-o1_uao))
            {
              return 3;
            }
            else
            {
              return 4;
            }
          }
        }
      }
      else
      {
        return 0;
      }
  }

bool Physics_engine::square_collision(Object const & o1,Object const & o2)
{
    return ((square_x_collision(o1,o2) && square_y_collision(o1,o2)) ||
	    (square_x_collision(o2,o1) && square_y_collision(o2,o1)));
}

bool Physics_engine::square_below_collision(Object const & o1,Object const & o2)
{
    return cordinate_between(o1.get_limits().upper,o2.get_limits().lower,o2.get_limits().upper);
}

bool Physics_engine::square_above_collision(Object const & o1,Object const & o2)
{
    return (cordinate_between(o1.get_limits().lower,o2.get_limits().lower,o2.get_limits().upper) && square_x_collision(o1,o2));
}

bool Physics_engine::square_y_collision(Object const & o1,Object const & o2)
{
    return (square_below_collision(o1,o2) || square_above_collision(o1,o2));
}

bool Physics_engine::square_x_collision(Object const & o1,Object const & o2)
{
    return (cordinate_between(o1.get_limits().left,o2.get_limits().right,o2.get_limits().left) ||
	    cordinate_between(o1.get_limits().right,o2.get_limits().right,o2.get_limits().left));
}

bool Physics_engine::cordinate_between(int x,int lowerorright,int upperorleft)
{
    return ((x <= lowerorright) && (x >= upperorleft));
}

bool Physics_engine::object_outside_x(Object const & obj)
{
    return ((obj.get_position().xpos > 1120) || (obj.get_position().xpos < 0));
}

bool Physics_engine::object_above (Object const & obj)
{
    return (obj.get_position().ypos < -2000);
}

bool Physics_engine::object_below (Object const & obj)
{
    return (obj.get_position().ypos > 720);
}

bool Physics_engine::object_outside (Object const & obj)
{
    return (object_outside_x(obj) || object_above(obj) || object_below(obj));
}



void Physics_engine::collision(Playing_field const & playing_field_obj, Player & player1, Player & player2) //const;
{
    player1.get_curr_character().set_in_air(true);
    player2.get_curr_character().set_in_air(true);
    player1.get_curr_character().set_is_stumped(false);
    player2.get_curr_character().set_is_stumped(false);

    if (square_above_collision(player1.get_curr_character(),playing_field_obj.get_platform()))
    {
        player1.get_curr_character().set_y_pos(playing_field_obj.get_platform().get_limits().upper - player1.get_curr_character().get_size().height);
        player1.get_curr_character().set_y_speed(0);
        player1.get_curr_character().set_in_air(false);
    }
    else
    {

        if (square_collision(player1.get_curr_character(),playing_field_obj.get_platform()))
        {
            player1.get_curr_character().set_x_pos(player1.get_curr_character().get_old_position().xpos);
            player1.get_curr_character().set_y_pos(player1.get_curr_character().get_old_position().ypos);
        }
    }
    if (square_above_collision(player2.get_curr_character(),playing_field_obj.get_platform()))
    {
        player2.get_curr_character().set_y_pos(playing_field_obj.get_platform().get_limits().upper - player2.get_curr_character().get_size().height);
        player2.get_curr_character().set_y_speed(0);
        player2.get_curr_character().set_in_air(false);
    }

    else
    {

        if (square_collision(player2.get_curr_character(),playing_field_obj.get_platform()))
        {
          player2.get_curr_character().set_x_pos(player2.get_curr_character().get_old_position().xpos);
          player2.get_curr_character().set_y_pos(player2.get_curr_character().get_old_position().ypos);
        }
    }

    if (square_super_collision(player1.get_curr_character(),player2.get_curr_character()) == 1)
      {
        player1.get_curr_character().set_x_pos(player1.get_curr_character().get_old_position().xpos);
        player2.get_curr_character().set_x_pos(player2.get_curr_character().get_old_position().xpos);
      }
    if (square_super_collision(player1.get_curr_character(),player2.get_curr_character()) == 3)
      {
        player1.get_curr_character().set_x_pos(player1.get_curr_character().get_old_position().xpos);
        player2.get_curr_character().set_x_pos(player2.get_curr_character().get_old_position().xpos);
      }

    if (square_super_collision(player1.get_curr_character(),player2.get_curr_character()) == 2)
      {
        player1.get_curr_character().set_in_air(false);
        player1.get_curr_character().set_y_pos(player2.get_curr_character().get_limits().upper - player1.get_curr_character().get_size().height);
        player1.get_curr_character().set_y_speed(0);
        player2.get_curr_character().set_is_stumped(true);
      }
    if (square_super_collision(player1.get_curr_character(),player2.get_curr_character()) == 4)
      {
        player2.get_curr_character().set_in_air(false);
        player2.get_curr_character().set_y_pos(player1.get_curr_character().get_limits().upper - player2.get_curr_character().get_size().height);
        player2.get_curr_character().set_y_speed(0);
        player1.get_curr_character().set_is_stumped(true);
      }

    if (object_below(player1.get_curr_character()))
    {
	     player1.get_curr_character().lose_health(9999);
    }
    if (object_below(player2.get_curr_character()))
    {
	     player2.get_curr_character().lose_health(9999);
    }

    if (object_above(player1.get_curr_character()))
    {
      player1.get_curr_character().set_y_speed(0);
      player1.get_curr_character().set_y_pos(player1.get_curr_character().get_old_position().ypos);
    }

    if (object_above(player2.get_curr_character()))
    {
      player2.get_curr_character().set_y_speed(0);
      player2.get_curr_character().set_y_pos(player2.get_curr_character().get_old_position().ypos);
    }
    if (object_outside (player1.get_curr_character()))
    {
        player1.get_curr_character().set_x_pos(player1.get_curr_character().get_old_position().xpos);
    }
    if (object_outside(player2.get_curr_character()))
    {
      player2.get_curr_character().set_x_pos(player2.get_curr_character().get_old_position().xpos);
    }

    for(std::vector<Projectile>::iterator it = player2.get_curr_character().get_projectiles().begin() ; it != player2.get_curr_character().get_projectiles().end(); it++)
    {
    	if (object_outside(*it))
    	{
    	  player2.get_curr_character().get_projectiles().erase(it);
        it--;
      }
      else
      {
      	if (square_collision(player1.get_curr_character(),*it))
      	 {
          player1.get_curr_character().lose_health((it->get_damage()));
          player2.get_curr_character().get_projectiles().erase(it);
          it--;
      	 }
       }
     }

for(std::vector<Projectile>::iterator it = player1.get_curr_character().get_projectiles().begin() ; it != player1.get_curr_character().get_projectiles().end(); it++)
    {
      if (object_outside(*it))
        {
          player1.get_curr_character().get_projectiles().erase(it);
          it--;
        }
      else
        {
          if (square_collision(player2.get_curr_character(),*it))
            {
               player2.get_curr_character().lose_health((it->get_damage()));
               player1.get_curr_character().get_projectiles().erase(it);
               --it;
            }
        }
    }
  }
