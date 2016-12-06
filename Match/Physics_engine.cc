//Physics engine cc

#include Physics_engine.h
#include <vector>
Physics_engine::Physics_engine()
{}

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
    c1 = player1.get_curr_character();
    c2 = player2.get_curr_character();
    c1.move(1);
    c2.move(1);
    if (square_above_collision(c1,c2) && square_x_collision(c1,c2))
    {
	      c1.set_ypos(c2.get_limits().upper - c1.get_size().height);
        c1.set_y_speed(0);
        c2.set_y_speed(0);
    }
    else
    {
    	if (square_above_collision(c2,c1) && square_x_collision(c2,c1))
    	{
    	    c2.set_ypos(c1.get_limits().upper - c2.get_size().height);
    	    c1.set_y_speed(0);
    	    c2.set_y_speed(0);
    	}
    	else
    	{
    	    if (Square_collision(c1,c2))
    	    {
        		c1.move(-1);
        		c2.move(-1);
    	    }
    	}
    }

    if (object_below(c1))
    {
	     c1.lose_health(9999);
    }
    if (object_below(c2))
    {
	     c2.lose_health(9999);
    }

    if (object_outside (c1))
    {
	     c1.move(-1);
    }
    if (object_outside(c2))
    {
	     c2.move(-1);
    }




    bool first_p1_iteration{true}
    //int p2_counter{0};
    for(std::vector<Projectile>::iterator it = c2.projectiles.begin() ; it != c2.projectile.end(); it++)
    {
    	p2 = *it;
    	p2.move();
    	if (object_outside(p2))
    	{
    	  c2.projectiles.erase(it);
        it--;
      }
      else
      {
    	if (square_collision(c1,p2))
    	 {
        c1.lose_health(p2.damage());
        c2.projectiles.erase(it);
        it--;
    	 }
     }
       for(std::vector<Projectile>::iterator it2 = c1.projectiles.begin() ; it2 != c1.projectile.end(); it2++)
    	  {
        	p1 = *it2;
        	if (first_p1_iteration)
        		{
        		    p1.move();
        		    if (object_outside(p1))
        		    {
        			c1.projectiles.erase(it2);
              it2--;
        		    }
                else
                {
        		    if (square_collision(c2,p1))
        		    {
        			c2.lose_health(p1.damage());
              c1.projectile.erase(it2);
              it2--;
        		    }
              }
                first_p1_iteration = false;
        		}
        		if (square_collision(p1,p2))
        		{
                c1.projectiles.erase(it2);
                c2.projectiles.erase(it);
                it--;
                it2--;
        		}
          }
        }

      	  }

  	  }

    for(std::vector<Platform>::iterator it = Playing_field.platforms.begin(); it != playing_field.patforms.end(); it++)
    {
    	plat = *it;
    	if (square_above_collision(c1,plat))
    	{
    	    c1.set_ypos(plat.lim.upper - c1.size.height);
    	    c1.set_y_speed(0);
    	}
    	else
    	{
    	    if (square_collision(c1,plat))
    	    {
    		c1.move(-1);
    	    }
    	}
    	if (square_above_collision(c2,plat))
    	{
    	    c2.set_ypos(plat.lim.upper - c2.size.height);
    	    c2.set_y_speed(0);
    	}

    	else
    	{
    	    if (square_collision(c2,plat))
    	    {
    		c2.move(-1);
    		//c2.set_y_speed(0);
    	    }
    	}
    }
  }

void Physics_engine::gravity(Playing_field & const playing_field_obj, Player & player1, Player & player2) //const;
	{
	    int gravity{1};
	    c1 = player1.get_curr_character();
	    c2 = player2.get_curr_character();
	    int c1_ground{0};
	    int c2_ground{0};

	    for(std::vector<Platform>::iterator it = Playing_field.platforms.begin(); it != playing_field.patforms.end(); it++)
	    {
		plat = *it;
		c1_ground += square_above_collision(c1,plat);
		c2_ground += square_above_collision(c2,plat);
	    }
	    c1.ground += square_collision_above(c1,c2);
	    c2.ground += square_collision_above(c2,c1);
	    if !(c1_ground)
	    {
		c1.set_y_speed(c1.get_y_speed() - gravity);
	    }

	    if !(c2.ground)
	    {
		c2.set_y_speed(c2.get_y_speed() - gravity);
	    }
