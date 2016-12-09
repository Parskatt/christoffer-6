//
//Character.h
//

#ifndef CHARACTER_H
#define CHARACTER_H

//#include "Match.h"
#include "Movable.h"
#include "Non_movables.h"
#include <memory>
#include "Attack.h"


class Character : public Movable
{
  private:

    struct Speed_vector
    {
	    int x_speed{};
	    int y_speed{};

    };

    Speed_vector speed_vector{};

    int health{};
    
    bool in_air{};

    Attack curr_attack{}; //Kanske måsvingar vid Attack

    bool has_attack;

    std::vector<Projectile> projectiles{};

    Health_bar health_bar;

    Position old_position{};


  public:

    ~Character() = default;

    Character() = default;

    Character(int,int,int,int,std::initializer_list<std::string>,int,int,int);//---------------------------------------------------------

    //Character & operator=(const Character &);

    void set_x_pos(int);

    void set_y_pos(int);

    void set_in_air(bool);

    void set_x_speed(int);

    void set_y_speed(int);

    bool get_in_air() const;

    int get_x_speed() const;

    int get_y_speed() const;

    int get_speed() const;

    Object::Position & get_old_position();

    void move() override;

    void move(int);

    void render(sf::RenderWindow &) override;

    //void jump();

    int get_texture_index();// override;

    void attack(int,int);

    void lose_health(int);

    std::vector<Projectile> & get_projectiles();

};

#endif
