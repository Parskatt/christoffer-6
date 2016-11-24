#include "Movable.h"
#include "Non_movables.h"
class Character : public Movable
{
private:
    struct Speed_vector
    {
	int x_speed{};
	int y_speed{};
    };
    int speed{};
    int health{};
    Health_bar health_bar;
    unique_ptr<Attack> curr_attack{};
public:
    Character(int,int,int,int,int,int,int};
    void set_x_speed(int);
    void set_y_speed(int);
    int get_y_speed();
    int get_x_speed();
    int get_speed();
    void move();
    void jump();
    int get_texture_index() override;
    void attack(int);
    void lose_health(int damage);
    
}
