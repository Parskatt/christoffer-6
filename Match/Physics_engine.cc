//Physics engine cc

#include Physics_engine.h
#include <vector>
Physics_engine::Physics_engine()

bool square_collision(o1 & const, o2 & const)
{
  return ((square_x_collision(o1,o2) and square_y_collision(o1,o2)) or 
	  (square_x_collision(o2,o1) and square_Y_collision(o2,o1)));

    //(cordinate_between(o1.lim.left,o2.lim.left,o2.lim.right) or cordinate_between(o1.lim.right,o2.lim.left,o2.lim.right)) and (cordinate_between(o1.lim.lower,o2.lim.lower,o2.lim.upper) or cordinate_between(o1.lim.upper,o2.lim.lower,o2.lim.upper)));
}

bool square_below_collision(o1 & const, o2 & const)
{ 
  return cordinate_between(o1.lim.upper,o2.lim.lower,o2.lim.upper);
}

bool square_above_collision(o1 & const, o2 & const)
{
  return cordinate_between(o1.lim.lower,o2.lim.lower,o2.lim.upper);
}

bool square_y_collision(o1 & const, o2 & const)
{
  return (square_below_collision(o1,o2) or square_above_collision(o1,o2));
}

bool square_x_collision(o1 & const, o2 & const)
{
  return (cordinate_between(o1.lim.left,o2.lim.left,o2.lim.right) or cordinate_between(o1.lim.right,o2.lim.left,o2.lim.right));
}

bool square_y_collide(o1, o2)
{
  if !(square_y_collision(o1,o2))
    {
      o1.move();
      o2.move();
      return square_y_collision(o1,o2);
    }
  return false;
}

    
bool cordinate_between(x,i1,i2)
   {
     return ((x >= i1) and (x <= i2));
   }

bool object_outside_x(Object & const obj)
{
  return ((obj.pos.x > 800) or (obj.pos.x < 0));
}

bool object_above (Object & const obj)
{
  return (obj.pos.y < 800);
}

bool object_below (Object & const obj) 
{
  return (obj.pos.y > 0);
}

bool object_outside (Object const obj)
{ 
  return (object_outside_x(obj) or object_above(obj) or object_below(obj));
}


void Physics_engine::collision(Playing_field & const playing_field_obj, Player & player1, Player & player2)
  nonmovable_objects &) const;
  {
    //int p1_check{0};
    //int p2_check{0};
    c1 = player1.get_curr_character();
    c2 = player2.get_curr_character();
    /*if (c1.get_projectile() == 0);
      {
      auto p1 = c1.get_projectile();
      p1_check = 1;
      }
      else
      {
      p1_check = 0;
      }
    */
    /*
      if (c2.get_projectile() == 0);
      {
      auto p2 = c1.get_projectile();
      p2_check = 1;
      }
      else
      {
      p2_check = 0;
      }
    */

    c1.move(0);
    c2.move(0);
    if (square_above_collision(c1,c2) and square_x_collision(c1,c2))
			       {
				 c1.set_ypos(c2.lim.upper - c1.size.height);
				 c1.set_y_speed(0);
				 c2.set_y_speed(0);
			       }
    else
      {
	if (square_above_collision(c2,c1) and square_x_collision(c2,c1))
	  {
	    c2.set_ypos(c1.lim.upper - c2.size.height);
	    c1.set_y_speed(0);
	    c2.set_y_speed(0);
	  }
	else
	  {
	    if Square_collision(c1,c2)
			 {
			   c1.move(-1);
			   c2.move(-1);
			 }
	  }
      }
  
    if object_below(c1)
      {
	c1.loose_health(9999);
      }
    if object_below(c2)
      {
	c2.loose_health(9999);
      }
    
    if object_outside (c1)
      {
	c1.move(-1);
      }
    if object_outside(c2)
      {
	c2.move(-1);
      }
    
    
    
    
    int first_p1_iteration{1}
    //int p2_counter{0};
    for(std::vector<Projectile>::iterator it = c2.projectiles.begin() ; it != c2.projectile.end(); it++)
      {
	p2 = *it;
	p2.move();
	if object_outside(p2)
	  {
	    p2.make_doomed();
	    //c2.projectiles.erase(c2.projectiles.begin + p2.counter);
	    
	    if square_collision(c1,p2)
				 {
				   c1.loose_health(p2.damage());
				   p2.make_doomed();
				   //c2.projectiles.erase(c2.projectiles.begin + p2.counter);
				   //p2_counter--;
				 }
	    //int p1_counter{0};
	    for(std::vector<Projectile>::iterator it2 = c1.projectiles.begin() ; it != c1.projectile.end(); it++)
	      {
		p1 = *it2;
		if first_p1_iteration
		  {
		    p1.move();
		    if object_outside(p1)
		      {
			p1.make_doomed();
			//c1.projectiles.erase(c1.projectiles.begin + p1.counter);
		      }
		    if square_collision(c2,p1)
					 {
					   c2.loose_health(p1.damage());
					   p1.make_doomed();
					   //c1.projectiles.erase(c1.projectiles.begin + p1.counter);
					 }
		  }
		if square_collision(p1,p2)
				     {
				       //c1.projectiles.erase(c1.projectiles.begin() + p1_counter);
				       //c2.projectiles.erase(c2.projectiles.begin() + p2_counter);
				       p1.make_doomed();
				       p2.make_doomed();
				     }
	  
		//p1_counter++;
	      }
	    first_pi_iteration = 0;
	    //p2_counter++;
	  }
	for std::vector<Platform>::iterator it = Playing_field.platforms.begin(); it != playingf_field.patforms.end(); it++) 
      {
	plat = *it;
	if square_collision(c1,plat)
			     {
			       c1.move(-1);
			       c1.set_y_speed(0);
			     }
	if square_collision(c2,plat)
			     {
			       c2.move(-1);
			       c2.set_y_speed(0);
			     }
      }
      
      int counter{0};
      for(std::vector<Projectile>::iterator it2 = c1.projectiles.begin() ; it != c1.projectile.end(); it++)
	{
	  p1 = *it2;
	  if first_p1_iteration
	    {
	      p1.move();
	      if object_outside(p1)
		{
		  p1.make_doomed();
		  //c1.projectiles.erase(c1.projectiles.begin + p1.counter);
		}
	      if square_collision(c2,p1)
				   {
				     c2.loose_health(p1.damage());
				     p1.make_doomed();
				     //c1.projectiles.erase(c1.projectiles.begin + p1.counter);
				   }
	    }
	  if square_collision(p1,p2)
			       {
				 //c1.projectiles.erase(c1.projectiles.begin() + p1_counter);
				 //c2.projectiles.erase(c2.projectiles.begin() + p2_counter);
				 p1.make_doomed();
				 p2.make_doomed();
			       }
	  
	  //p1_counter++;
	  first_pi_iteration = 0;
	}
      //p2_counter++;
      for(std::vector<Platform>::iterator it = Playing_field.platforms.begin(); it != playing_field.patforms.end(); it++) 
	{
	  plat = *it;
	  if square_above_collision(c1,plat)
				     {
				       c1.set_ypos(plat.lim.upper - c1.size.height);
				       c1.set_y_speed(0);
				     }
	  else 
	    {
	    if square_collision(c1,plat)
				 {
				   c1.move(-1);
				   //c1.set_y_speed(0);
				 }
	    }
	  if square_above_collision(c2,plat)
				     {
				       c2.set_ypos(plat.lim.upper - c2.size.height);
				       c2.set_y_speed(0);
				     }

	  else
	    {
	      if square_collision(c2,plat)
				   {
				     c2.move(-1);
				     //c2.set_y_speed(0);
				   }
	    }
      
      int counter{0};
      
      for(std::vector<Projectile>::iterator it = c1.projectiles.begin() ; it != c1.projectile.end(); it++)
	{
	  c1 = *it;
	  if c1.is_doomed()
		  {
		    c1.projectiles.erase(c1.projectiles.begin() + counter);
		    counter--;
		  }
	  counter++;
	}
      counter = 0;

          for(std::vector<Projectile>::iterator it = c1.projectiles.begin() ; it != c1.projectile.end(); it++)
	{
	  c2 = *it;
	  if c2.is_doomed()
		  {
		    c2.projectiles.erase(c2.projectiles.begin() + counter);
		    counter--;
		  }
	  counter++;
	}
  }

void Physics_engine::gravity(Playing_field & const playing_field_obj, Player & player1, Player & player2)
  nonmovable_objects &) const;
  {
    int gravity{10};
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

   
