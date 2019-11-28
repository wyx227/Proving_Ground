#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main()
{
    int caliber;
    double caliber_caculation;
    int initial_velocity;
    double launching_angle;
    int Krupp;
    double Krupp_calculation;
    int shell_weight;
    double air_drag;
    double area;
    double rho = 1.2;
    double gravity = 9.81;
    double Coefficient;
    double vx;
    double vy;
    double dt = 0.01;
    double v;
    double ax;
    double ay;
    double pi = 3.14;
    double penetration;
    
    printf("Caliber in mm: \n");
	scanf("%i",&caliber);
    printf("Initial velocity in m/s: \n");
    scanf("%i",&initial_velocity);
    printf("Shell weight in kg: \n");
    scanf("%i",&shell_weight);
    printf("Air Drag Coefficient: \n");
    scanf("%lf",&air_drag);
    printf("Launching Angle: \n");
    scanf("%lf",&launching_angle);
    printf("Krupp Value: \n");
    scanf("%i",&Krupp);
    
    caliber_caculation = (double)caliber / 1000.0;
    area = pi * (caliber_caculation/2)*(caliber_caculation/2);
    Coefficient = rho * air_drag* area/2.0;
    Krupp_calculation = (double)Krupp/2400.0*0.5561613;
    
    vx = (double)initial_velocity * cos(launching_angle*pi/180.0);
    vy = (double)initial_velocity * sin(launching_angle*pi/180.0);
    
    int t=0;
    double x = 0;
    double y=0;
    
    do{
        ax = -(Coefficient/(double)shell_weight)*(double)initial_velocity*vx;
        ay = -gravity-(Coefficient/(double)shell_weight)*(double)initial_velocity*vy;
        vx = vx+ax*dt;
        vy = vy+ay*dt;
        
        x=x+vx*dt+0.5*ax*dt*dt;
        y=y+vy*dt+0.5*ay*dt*dt;
        t=t+dt;
    
    }while(y>-0.01);
    
    v = sqrt(vx*vx+vy*vy);
    penetration=Krupp_calculation*pow(v,1.1)*pow(shell_weight,0.55)/pow((double)caliber,0.65);
    printf("Range: %.0lf m\n",x);
    printf("Velocity: %.2lf m/s\n",v);
    printf("Penetration at this range: %.2lf mm\n",penetration);
    system("pause");
    
	
}
