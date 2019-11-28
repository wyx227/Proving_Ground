#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main()
{
    double caliber;
    double caliber_caculation;
    double initial_velocity;
    double launching_angle;
    double range;
    double Krupp;
    double Krupp_calculation;
    double shell_weight;
    double air_drag;
    double area;
    double Coefficient;
    double vx;
    double vy;
    double v;

    double pi = 3.14;
    double penetration;
    double fall_angle;
	double verti_pen;
	
	double rho = 1.2;
    double gravity = 9.81;
    double dt = 0.01;

	double cw_1 = 1;
	double cw_2;
	double t_0 = 288;
	double L = 0.0065;
	double p_0 = 101325;
	double R=8.31447;
	double M = 0.0289644;
	double T;
	double P;
    
    printf("Caliber in mm: \n");
	scanf("%lf",&caliber);
    printf("Initial velocity in m/s: \n");
    scanf("%lf",&initial_velocity);
    printf("Shell weight in kg: \n");
    scanf("%lf",&shell_weight);
    printf("Air Drag Coefficient: \n");
    scanf("%lf",&air_drag);
    printf("Range: \n");
    scanf("%lf",&range);
    printf("Krupp Value: \n");
    scanf("%lf",&Krupp);
    
    caliber_caculation = caliber / 1000.0;
    area = pi * (caliber_caculation/2)*(caliber_caculation/2);
    Coefficient = rho * air_drag/shell_weight* area/2.0;
    Krupp_calculation = Krupp/2400.0*0.5561613;
    cw_2=100+1000/3*0.001*caliber;
   
    

    for (int i=1;i<4501;i++){
        vx = (double)initial_velocity * cos(i*0.01*pi/180.0);
        vy = (double)initial_velocity * sin(i*0.01*pi/180.0);
        double t=0;
        double x = 0;
        double y=0;       
        do{
			x = x+dt*vx;
			y = y+dt*vy;
			
			T=t_0 - L*y;
			P=p_0 * pow((1-L*y/t_0),(gravity * M/(R*L)));
			rho = P*M/(R*T);
			
			vx=vx-dt*Coefficient*rho*(cw_1*pow(vx,2)+cw_2*vx);
			
			vy=vy-dt*gravity-dt*Coefficient*(cw_1*pow(vy,2)+cw_2*fabs(vy))*signbit(vy);
			
			t=t+dt;
    
        }while(y>-0.01);
        if (fabs(x-range)/range < 0.005){
            launching_angle=0.01*i;
            v = sqrt(vx*vx+vy*vy);
            fall_angle=atan(fabs(vy)/vx)*180/pi;
            goto end;
        }
    }
    

    
    end:
        penetration=Krupp_calculation*pow(v,1.1)*pow(shell_weight,0.55)/pow(caliber,0.65);
		verti_pen = penetration * sin(fall_angle*pi/180.0);
        printf("Range: %lf m\n",range);
        printf("Velocity: %.2lf m/s\n",v);
        printf("Angle: %.2lf\n",launching_angle);
        printf("Falling Angle: %.2lf\n",fall_angle);
        printf("Penetration at this range: %.2lf mm\n",penetration);
		printf("Vertical Peneration: %.2lf mm\n",verti_pen);
        system("pause");

	
}