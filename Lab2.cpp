#include <iostream>
using namespace std;



class Quat
{
    private:
        int Q[4];
    public:

    void setq(int a, int b, int c, int d)
    {
        Q[0] = a;
        Q[1] = b;
        Q[2] = c;
        Q[3] = d;
    }

    void printq()
    {
       for(int i=0; i<4; i++)
       {
           cout << Q[i] << ", ";
       }
       cout << endl;
    }
    
    Quat operator+(Quat other)
    {
        Quat some;
        for(int i=0; i<4; i++){
            some.Q[i] = Q[i] + other.Q[i];
        }
        return some;
    }
    
    Quat operator-(Quat other)
    {
        Quat some;
        for(int i=0; i<4; i++){
            some.Q[i] = Q[i] - other.Q[i];
        }
        return some;
    }
    Quat operator*(Quat other)
    {
        Quat some;
        some.Q[0] = ((Q[0] * other.Q[0]) - (Q[1] * other.Q[1]) - (Q[2] * other.Q[2]) - (Q[3] * other.Q[3]));
        some.Q[1] = ((Q[1] * other.Q[0]) + (Q[0] * other.Q[1]) - (Q[3] * other.Q[2]) + (Q[2] * other.Q[3]));
        some.Q[2] = ((Q[2] * other.Q[0]) + (Q[3] * other.Q[1]) + (Q[0] * other.Q[2]) + (Q[0] * other.Q[3]));
        some.Q[3] = ((Q[3] * other.Q[0]) - (Q[2] * other.Q[1]) + (Q[1] * other.Q[2]) - (Q[0] * other.Q[3]));
        
        return some;
    }
};

int main()
{
    Quat xQuat;
    Quat yQuat;
    Quat testq;

    xQuat.setq(1, 2, 3, 4);
    xQuat.printq();
    yQuat.setq(4, 3, 2, 1);
    yQuat.printq();
    
    testq = xQuat + yQuat;
    testq.printq();
    
    testq = xQuat - yQuat;
    testq.printq();
    
    testq = xQuat * yQuat;
    testq.printq();
    
    xQuat.setq(0, 1, 0, 1);
    yQuat.setq(0, 1, 0, 0);
    testq = xQuat * yQuat;
    testq.printq();

    return 0;
}
