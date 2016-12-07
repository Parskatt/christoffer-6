//Physics engine cc

#include "Physics_engine.h"
#include <vector>



bool Physics_engine::square_collision(Object const & o1,Object const & o2)
{
    return ((square_x_collision(o1,o2) && square_y_collision(o1,o2)) ||
	    (square_x_collision(o2,o1) && square_Y_collision(o2,o1)));
}

bool Physics_engine::square_below_collision(Object const & o1,Object const & o2)
{
    return cordinate_between(o1.get_limits().upper,o2.get_limits().lower,o2.get_limits().upper);
}

bool Physics_engine::square_above_collision(Object const & o1,Object const & o2)
{
    return cordinate_between(o1.get_limits().lower,o2.get_limits().lower,o2.get_limits().upper);
}

bool Physics_engine::square_y_collision(Object const & o1,Object const & o2)
{
    return (square_below_collision(o1,o2) || square_above_collision(o1,o2));
}

bool Physics_engine::square_x_collision(Object const & o1,Object const & o2)
{
    return (cordinate_between(o1.get_limits().left,o2.get_limits().left,o2.get_limits().right) ||
	    cordinate_between(o1.get_limits().right,o2.get_limits().left,o2.get_limits().right));
}

bool Physics_engine::square_y_collide(Object const & o1,Object const & o2)
{
    if !(square_y_collision(o1,o2))
    {
    	o1.move();
    	o2.move();
    	return square_y_collision(o1,o2);
    }
    return false;
}


bool Physics_engine::cordinate_between(int x,int left,int right)
{
    return ((x >= left) && (x <= right));
}

bool Physics_engine::object_outside_x(Object const & obj)
{
    return ((obj.get_position().x > 1280) || (obj.get_position().x < 0));
}

bool Physics_engine::object_above (Object const & obj)
{
    return (obj.get_position().y < 0);
}

bool Physics_engine::object_below (Object const & obj)
{
    return (obj.get_position().y > 720);
}

bool Physics_engine::object_outside (Object const & obj)
{
    return (object_outside_x(obj) || object_above(obj) || object_below(obj));
}


void Physics_engine::collision(Playing_field const & playing_field_obj, Player & player1, Player & player2) //const;
{
    //int p1_check{0};
    //int p2_check{0};
    //c1 = player1.get_curr_character();
    //c2 = player2.get_curr_character();
    player1.get_curr_character().move(1);
    player2.get_curr_character().move(1);
    if (square_above_collision(player1.get_curr_character(),player2.get_curr_character()) && square_x_collision(player1.get_curr_character(),player2.get_curr_character()))
    {
	      player1.get_curr_character().set_ypos(player2.get_curr_character().get_limits().upper - player1.get_curr_character().get_size().height);
        player1.get_curr_character().set_y_speed(0);
        player2.get_curr_character().set_y_speed(0);
    }
    else
    {
    	if (square_above_collision(player2.get_curr_character(),player1.get_curr_character()) && square_x_collision(player2.get_curr_character(),player1.get_curr_character()))
    	{
    	    player2.get_curr_character().set_ypos(player1.get_curr_character().get_limits().upper - player2.get_curr_character().get_size().height);
    	    player1.get_curr_character().set_y_speed(0);
    	    player2.get_curr_character().set_y_speed(0);
    	}
    	else
    	{
    	    if (Square_collision(player1.get_curr_character(),player2.get_curr_character()))
    	    {
        		player1.get_curr_character().move(-1);
        		player2.get_curr_character().move(-1);
    	    }
    	}
    }

    if (object_below(player1.get_curr_character()))
    {
	     player1.get_curr_character().lose_health(9999);
    }
    if (object_below(player2.get_curr_character()))
    {
	     player2.get_curr_character().lose_health(9999);
    }

    if (object_outside (player1.get_curr_character()))
    {
	     player1.get_curr_character().move(-1);
    }
    if (object_outside(player2.get_curr_character()))
    {
	     player2.get_curr_character().move(-1);
    }




    bool first_p1_iteration{true};
    //int p2_counter{0};
    for(std::vector<Projectile>::iterator it = player2.get_curr_character().projectiles.begin() ; it != player2.get_curr_character().projectile.end(); it++)
    {
    	//p2 = *it;
    	*it.move();
    	if (object_outside(*it))
    	{
    	  player2.get_curr_character().projectiles.erase(it);
        it--;
      }
      else
      {
      	if (square_collision(player1.get_curr_character(),*it))
      	 {
          player1.get_curr_character().lose_health(*it.damage());
          player2.get_curr_character().projectiles.erase(it);
          it--;
      	 }
       }

       for(std::vector<Projectile>::iterator it2 = player1.get_curr_character().projectiles.begin() ; it2 != player1.get_curr_character().projectile.end(); it2++)
    	{
        	//p1 = *it2;
        	if (first_p1_iteration)
        		{
        		    *it2.move();
        		    if (object_outside(p1))
        		    {
            			player1.get_curr_character().projectiles.erase(it2);
                  it2--;
        		    }
                else
                {
        		    if (square_collision(player2.get_curr_character(),*it2))
        		    {
        			player2.get_curr_character().lose_health(*it2.damage());
              player1.get_curr_character().projectile.erase(it2);
              it2--;
        		    }
              }
                first_p1_iteration = false;
        		}
        		if (square_collision(*it2,*it))
        		{
                player1.get_curr_character().projectiles.erase(it2);
                player2.get_curr_character().projectiles.erase(it);
                it--;
                it2--;
        		}
          }
        }





    //for(std::vector<Platform>::iterator it = Playing_field.platforms.begin(); it != playing_field.patforms.end(); it++)
    //
    //	plat = *it;
    	if (square_above_collision(player1.get_curr_character(),playing_field_obj.get_platform()))
    	{
    	    player1.get_curr_character().set_ypos(playing_field_obj.get_platform().get_limits().upper - player1.get_curr_character().get_size().height);
    	    player1.get_curr_character().set_y_speed(0);
    	}
    	else
    	{
    	    if (square_collision(player1.get_curr_character(),playing_field_obj.get_platform()))
    	    {
    		      player1.get_curr_character().move(-1);
    	    }
    	}
    	if (square_above_collision(player2.get_curr_character(),playing_field_obj.get_platform()))
    	{
    	    player2.get_curr_character().set_ypos(playing_field_obj.get_platform().get_limits().upper - player2.get_curr_character().get_size().height);
    	    player2.get_curr_character().set_y_speed(0);
    	}

    	else
    	{
    	    if (square_collision(player2.get_curr_character(),playing_field_obj.get_platform()))
    	    {
    		player2.get_curr_character().move(-1);
    		//c2.set_y_speed(0);
    	    }
    	}

  }

void Physics_engine::gravity(Playing_field & const playing_field_obj, Player & player1, Player & player2) //const;
{
    int gravity{1};
    //c1 = player1.get_curr_character();
    //player2.get_curr_character() = player2.get_curr_character();
    int c1_ground{0};
    int c2_ground{0};

    //for(std::vector<Platform>::iterator it = playing_field_obj.platform.begin(); it != playing_field_obj.platform.end(); it++)
    //{
    //plat = *it;
    	c1_ground += square_above_collision(player1.get_curr_character(),playing_field_obj.get_platform());
    	c2_ground += square_above_collision(player2.get_curr_character(),playing_field_obj.get_platform());
    //}
    c1_ground += square_collision_above(player1.get_curr_character(),player2.get_curr_character());
    c2_ground += square_collision_above(player2.get_curr_character(),player1.get_curr_character());

    if(!c1_ground)
    {
    	player1.get_curr_character().set_y_speed(player1.get_curr_character().get_y_speed() - gravity);
    }

    if(!c2_ground)
    {
    	player2.get_curr_character().set_y_speed(player2.get_curr_character().get_y_speed() - gravity);
    }
}
