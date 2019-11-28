#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main()
{
    int caliber;
    double caliber_caculation;
    int initial_velocity;
    double launching_angle;
    int range;
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
    double fall_angle;
    
    printf("Caliber in mm: \n");
	scanf("%i",&caliber);
    printf("Initial velocity in m/s: \n");
    scanf("%i",&initial_velocity);
    printf("Shell weight in kg: \n");
    scanf("%i",&shell_weight);
    printf("Air Drag Coefficient: \n");
    scanf("%lf",&air_drag);
    printf("Range: \n");
    scanf("%i",&range);
    printf("Krupp Value: \n");
    scanf("%i",&Krupp);
    
    caliber_caculation = (double)caliber / 1000.0;
    area = pi * (caliber_caculation/2)*(caliber_caculation/2);
    Coefficient = rho * air_drag* area/2.0;
    Krupp_calculation = (double)Krupp/2400.0*0.5561613;
    
   
    

    for (int i=1;i<4501;i++){
        vx = (double)initial_velocity * cos(i*0.01*pi/180.0);
        vy = (double)initial_velocity * sin(i*0.01*pi/180.0);
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
        if (abs(x-range)/(double)range < 0.005){
            launching_angle=0.01*i;
            v = sqrt(vx*vx+vy*vy);
            fall_angle=90-abs(atan(vx/vy)*180/pi);
            goto end;
        }
    }
    

    
    end:
        penetration=Krupp_calculation*pow(v,1.1)*pow(shell_weight,0.55)/pow((double)caliber,0.65);
        printf("Range: %i m\n",range);
        printf("Velocity: %.2lf m/s\n",v);
        printf("Angle: %.2lf\n",launching_angle);
        printf("Falling Angle: %.2lf\n",fall_angle);
        printf("Penetration at this range: %.2lf mm\n",penetration);
        system("pause");

	
}