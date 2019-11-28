#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
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
char ship_name[128]; 
double fall_angle;
double verti_pen;
bool USN;
bool HMS;

double cw_1 = 1;
double cw_2;
double t_0 = 288;
double L = 0.0065;
double p_0 = 101325;
double R=8.31447;
double M = 0.0289644;
double T;
double P;

void get_Datas(){
	scanf("%s",&ship_name[0]);
    if (strcmp(ship_name,"USN_DD")==0){
        caliber = 127;
        initial_velocity = 792;
        Krupp = 2598;
        shell_weight = 25;
        air_drag = 0.347;
    }else if(strcmp(ship_name,"Sampson")==0){
		caliber = 102;
		initial_velocity = 884;
        Krupp =1451;
        shell_weight = 15;
        air_drag = 0.33;
    }else if(strcmp(ship_name,"Smith")==0){
		caliber = 76;
		initial_velocity = 823;
        Krupp =2480;
        shell_weight = 6;
        air_drag = 0.47;
    }else if(strcmp(ship_name,"Wickes")==0){
		caliber = 102;
		initial_velocity = 884;
        Krupp =1451;
        shell_weight = 15;
        air_drag = 0.33;
    }else if(strcmp(ship_name,"Clemson")==0){
		caliber = 102;
		initial_velocity = 884;
        Krupp =1451;
        shell_weight = 15;
        air_drag = 0.33;
    }else if(strcmp(ship_name,"Nicolas_Stock")==0){
		caliber = 127;
		initial_velocity = 960;
        Krupp =1400;
        shell_weight = 23;
        air_drag = 0.36;
    }else if(strcmp(ship_name,"Omaha")==0){
		caliber = 152;
		initial_velocity = 914;
        Krupp =1772;
        shell_weight = 48;
        air_drag = 0.3164;
    }else if(strcmp(ship_name,"Cleveland")==0){
		caliber = 152;
		initial_velocity = 762;
        Krupp =2445;
        shell_weight = 59;
        air_drag = 0.322;
    }else if (strcmp(ship_name,"USN_203mm")==0){
        caliber = 203;
		initial_velocity = 853;
        Krupp =2846;
        shell_weight = 118;
        air_drag = 0.321;
		USN = true;
    }else if (strcmp(ship_name,"USN_203mm_Superheavy")==0){
        caliber = 203;
        initial_velocity = 762;
        Krupp = 2919;
        shell_weight = 152;
        air_drag = 0.356;
		USN=true;
    }else if(strcmp(ship_name,"South_Carolina")==0){
		caliber = 305;
		initial_velocity = 823;
        Krupp =2408;
        shell_weight = 395;
        air_drag = 0.435;
    }else if(strcmp(ship_name,"Wyoming")==0){
		caliber = 305;
		initial_velocity = 884;
        Krupp =2523;
        shell_weight = 395;
        air_drag = 0.337;
    }else if(strcmp(ship_name,"Arizona")==0){
		caliber = 356;
		initial_velocity = 792;
        Krupp =2604;
        shell_weight = 680;
        air_drag = 0.332;
    }else if (strcmp(ship_name,"USN_356mm")==0){
        caliber = 356;
        initial_velocity = 792;
        Krupp =2604;
        shell_weight = 680;
        air_drag = 0.332;
    }else if (strcmp(ship_name,"New_York_A")==0){
        caliber =356;
        initial_velocity = 792;
        Krupp =1603;
        shell_weight = 635;
        air_drag = 0.366;
    }else if (strcmp(ship_name,"Colorado")==0){
        caliber =406;
        initial_velocity =768;
        Krupp =2636;
        shell_weight =1068;
        air_drag =0.336;
    }else if (strcmp(ship_name,"Mk6")==0){
        caliber = 406;
        initial_velocity = 701;
        Krupp =2598;
        shell_weight = 1225;
        air_drag = 0.352;
		USN=true;
    }else if (strcmp(ship_name,"Mk7")==0){
        caliber =406;
        initial_velocity = 762;
        Krupp =2520;
        shell_weight =1225;
        air_drag =0.352;
		USN=true;
    }else if (strcmp(ship_name,"IJN_140mm")==0){
        caliber = 140;
        initial_velocity = 850;
        Krupp =1794;
        shell_weight = 38;
        air_drag = 0.3696;
    }else if (strcmp(ship_name,"IJN_CA_Tier_5-9")==0){
        caliber =203;
        initial_velocity =840;
        Krupp =2468;
        shell_weight =126;
        air_drag =0.337;
    }else if (strcmp(ship_name,"Zao")==0){
        caliber = 203;
        initial_velocity = 920;
        Krupp =2468;
        shell_weight = 155;
        air_drag = 0.337;
    }else if (strcmp(ship_name,"Mogami")==0){
		caliber = 155;
        initial_velocity = 56;
        Krupp =2429;
        shell_weight = 925;
        air_drag = 0.335;
    }else if(strcmp(ship_name,"Umikaze")==0){
		caliber = 120;
		initial_velocity = 660;
        Krupp =1750;
        shell_weight = 20;
        air_drag = 0.331;
    }else if(strcmp(ship_name,"Tachibana")==0){
		caliber = 76;
		initial_velocity = 690;
        Krupp =1250;
        shell_weight = 7;
        air_drag = 0.35;
    }else if(strcmp(ship_name,"Isokaze")==0){
		caliber = 120;
		initial_velocity = 660;
        Krupp =1750;
        shell_weight = 20;
        air_drag = 0.331;
    }else if(strcmp(ship_name,"Minekaze")==0){
		caliber = 120;
		initial_velocity = 825;
        Krupp =1750;
        shell_weight = 20;
        air_drag = 0.331;
    }else if (strcmp(ship_name,"IJN_127mm")==0){
        caliber = 127;
        initial_velocity = 915;
        Krupp = 2266;
        shell_weight = 23;
        air_drag = 0.334;
    }else if (strcmp(ship_name,"Akizuki")==0){
        caliber = 100;
        initial_velocity = 1000;
        Krupp =2154;
        shell_weight = 13;
        air_drag = 0.3137;
    }else if (strcmp(ship_name,"IJN_356mm")==0){
        caliber = 356;
        initial_velocity = 775;
        Krupp =2657;
        shell_weight = 674;
        air_drag = 0.331;
    }else if (strcmp(ship_name,"IJN_410mm")==0){
        caliber = 410;
        initial_velocity = 775;
        Krupp =2711;
        shell_weight = 1020;
        air_drag = 0.365;
    }else if (strcmp(ship_name,"Izumo")==0){
        caliber = 410;
        initial_velocity = 806;
        Krupp =2711;
        shell_weight = 1020;
        air_drag = 0.365;
    }else if (strcmp(ship_name,"Yamato")==0){
        caliber =460;
        initial_velocity =780;
        Krupp =2574;
        shell_weight = 1460;
        air_drag = 0.292;
    }else if(strcmp(ship_name,"Storozhevoi")==0){
		caliber = 120;
		initial_velocity = 823;
        Krupp =1488;
        shell_weight = 18;
        air_drag = 0.3756;
    }else if(strcmp(ship_name,"VMF_130_Old")==0){
		caliber = 130;
		initial_velocity = 861;
        Krupp =1652;
        shell_weight = 34;
        air_drag = 0.291;
    }else if (strcmp(ship_name,"VMF_B130")==0){
        caliber = 130;
        initial_velocity = 870;
        Krupp =1700;
        shell_weight = 33.5;
        air_drag = 0.2857;
    }else if (strcmp(ship_name,"VMF_B2-U")==0){
        caliber = 130 ;
        initial_velocity = 900;
        Krupp =1720;
        shell_weight = 33.5;
        air_drag = 0.2549;
    }else if (strcmp(ship_name,"Grozovoi")==0){
        caliber = 130;
        initial_velocity = 950;
        Krupp = 1900;
        shell_weight = 33.5;
        air_drag = 0.255;
    }else if (strcmp(ship_name,"Kirov")==0){
        caliber = 180;
        initial_velocity = 800;
        Krupp =2300;
        shell_weight = 97.5;
        air_drag = 0.3096;
    }else if (strcmp(ship_name,"VMF_152mm")==0){
        caliber = 152;
        initial_velocity = 950;
        Krupp =2216;
        shell_weight = 55;
        air_drag = 0.321;
    }else if (strcmp(ship_name,"VMF_180mm_new")==0){
        caliber = 180;
        initial_velocity = 920;
        Krupp =2370;
        shell_weight = 97.5;
        air_drag = 0.2778;
    }else if (strcmp(ship_name,"Moskva")==0){
        caliber =220;
        initial_velocity =985;
        Krupp =2590;
        shell_weight =176;
        air_drag =0.2549;
    }else if(strcmp(ship_name,"Imperator")==0){
		caliber = 305;
		initial_velocity = 762;
        Krupp =2627;
        shell_weight = 471;
        air_drag = 0.4595;
    }else if(strcmp(ship_name,"October_Revolution")==0){
		caliber = 305;
		initial_velocity = 762;
        Krupp =2627;
        shell_weight = 471;
        air_drag = 0.4595;
    }else if (strcmp(ship_name,"KMS_DD_128mm")==0){
        caliber = 128;
        initial_velocity = 830;
        Krupp = 1640;
        shell_weight = 25;
        air_drag = 0.35;
    }else if (strcmp(ship_name,"KMS_DD_150mm_and_CL")==0){
        caliber = 150;
        initial_velocity = 960;
        Krupp =1862;
        shell_weight = 45.5;
        air_drag = 0.3307;
    }else if (strcmp(ship_name,"Yorck")==0){
        caliber = 210;
        initial_velocity = 900;
        Krupp =2545;
        shell_weight = 108;
        air_drag = 0.4808;
    }else if (strcmp(ship_name,"KMS_CA")==0){
        caliber = 203;
        initial_velocity = 925;
        Krupp =2409;
        shell_weight = 122;
        air_drag = 0.2974;
    }else if(strcmp(ship_name,"Nassau")==0){
		caliber = 283;
		initial_velocity = 855;
        Krupp =2789;
        shell_weight = 302;
        air_drag = 0.5337;
    }else if(strcmp(ship_name,"Kaiser_Stock")==0){
		caliber = 305;
		initial_velocity = 855;
        Krupp =2311;
        shell_weight = 405;
        air_drag = 0.4195;
    }else if(strcmp(ship_name,"Kaiser")==0){
		caliber = 305;
		initial_velocity = 850;
        Krupp =2289;
        shell_weight = 415;
        air_drag = 0.3093;
    }else if (strcmp(ship_name,"König")==0){
        caliber = 305;
        initial_velocity = 850;
        Krupp =2289;
        shell_weight = 415;
        air_drag = 0.3093;
    }else if (strcmp(ship_name,"Scharnhorst")==0){
        caliber = 283;
        initial_velocity = 890;
        Krupp = 2312;
        shell_weight = 330;
        air_drag = 0.2827;
    }else if (strcmp(ship_name,"Bayern")==0){
        caliber = 380;
        initial_velocity = 800;
        Krupp =2454;
        shell_weight = 750;
        air_drag = 0.4092;
    }else if (strcmp(ship_name,"KMS_380mm")==0){
        caliber = 380;
        initial_velocity = 820;
        Krupp =2450;
        shell_weight = 800;
        air_drag = 0.2763;
    }else if (strcmp(ship_name,"KMS_406mm")==0){
        caliber = 406;
        initial_velocity = 810;
        Krupp =2527;
        shell_weight = 1030;
        air_drag = 0.299;
    }else if (strcmp(ship_name,"KMS_420mm")==0){
        caliber = 420;
        initial_velocity = 800;
        Krupp =2420;
        shell_weight =1220;
        air_drag =0.299;
    }else if (strcmp(ship_name,"Dunkerque")==0){
        caliber =330;
        initial_velocity = 870;
        Krupp = 2428;
        shell_weight = 560;
        air_drag = 0.2801;
    }else if(strcmp(ship_name,"Jurien")==0){
		caliber = 165;
		initial_velocity = 770;
        Krupp =1883;
        shell_weight = 54;
        air_drag = 0.42;
    }else if(strcmp(ship_name,"Friant")==0){
		caliber = 139;
		initial_velocity = 790;
        Krupp =2041;
        shell_weight = 40;
        air_drag = 0.3916;
    }else if(strcmp(ship_name,"Trouin")==0){
		caliber = 155;
		initial_velocity = 870;
        Krupp =2214;
        shell_weight = 57;
        air_drag = 0.3401;
    }else if(strcmp(ship_name,"Emile_Bertin")==0){
		caliber = 152;
		initial_velocity = 870;
        Krupp =2184;
        shell_weight = 56;
        air_drag = 0.3226;
    }else if(strcmp(ship_name,"Algerie")==0){
		caliber = 203;
		initial_velocity = 820;
        Krupp =2434;
        shell_weight = 134;
        air_drag = 0.33;
    }else if(strcmp(ship_name,"Charle_Martel")==0){
		caliber = 203;
		initial_velocity = 845;
        Krupp =2434;
        shell_weight = 134;
        air_drag = 0.33;
    }else if(strcmp(ship_name,"Henri_IV")==0){
		caliber = 240;
		initial_velocity = 845;
        Krupp =2882;
        shell_weight = 220;
        air_drag = 0.2764;
    }else if (strcmp(ship_name,"HMS_Low_Tier_152mm")==0){
        caliber = 152;
        initial_velocity = 841;
        Krupp =2609;
        shell_weight = 50.8;
        air_drag = 0.33;
		HMS=true;
    }else if (strcmp(ship_name,"HMS_High_Tier_152mm")==0){
        caliber = 152;
        initial_velocity = 768;
        Krupp =2672;
        shell_weight = 59;
        air_drag = 0.3475;
        HMS=true;
    }else if(strcmp(ship_name,"Duca")==0){
		caliber = 152;
		initial_velocity = 1000;
        Krupp =0.3256;
        shell_weight = 50;
        air_drag = 0.3256;
    }else if (strcmp(ship_name,"Warspite")==0){
        caliber = 381;
        initial_velocity = 732;
        Krupp = 2330;
        shell_weight = 879;
        air_drag = 0.3415;
    }else if (strcmp(ship_name,"Blyskawica")==0){
        caliber = 120;
        initial_velocity = 900;
        Krupp = 1721;
        shell_weight = 24;
        air_drag = 0.3177;
    }else if (strcmp(ship_name,"Iron_Duke")==0){
        caliber = 343;
        initial_velocity = 759;
        Krupp = 2031;
        shell_weight = 635;
        air_drag = 0.45;
    }else if (strcmp(ship_name,"Hood")==0){
        caliber = 381;
        initial_velocity = 731;
        Krupp = 2190;
        shell_weight = 879;
        air_drag = 0.36;
    }else if (strcmp(ship_name,"Nelson")==0){
        caliber = 406;
        initial_velocity = 788;
        Krupp = 2266;
        shell_weight = 929;
        air_drag = 0.35;
    }else if (strcmp(ship_name,"KGV")==0){
        caliber = 356;
        initial_velocity = 757;
        Krupp = 2295;
        shell_weight = 721;
        air_drag = 0.31;
    }else if (strcmp(ship_name,"Monarch")==0){
        caliber = 381;
        initial_velocity = 836;
        Krupp = 2250;
        shell_weight = 879;
        air_drag = 0.36;
    }else if (strcmp(ship_name,"Lion")==0){
        caliber = 406;
        initial_velocity = 747;
        Krupp = 2527;
        shell_weight = 1080;
        air_drag = 0.24;
    }else if (strcmp(ship_name,"Conqueror_419mm")==0){
        caliber = 419;
        initial_velocity = 747;
        Krupp = 2548;
        shell_weight = 1157;
        air_drag = 0.24;
    }else if (strcmp(ship_name,"Conqueror_457mm")==0){
        caliber = 457;
        initial_velocity = 762;
        Krupp = 2485;
        shell_weight = 1506;
        air_drag = 0.29;
    }
}

void Calculate_Projectile(){

    caliber_caculation = (double)caliber / 1000.0;
    area = pi * (caliber_caculation/2)*(caliber_caculation/2);
    Coefficient = rho * air_drag/(double)shell_weight* area/2.0;
    Krupp_calculation = (double)Krupp/2400.0*0.5561613;
	cw_2=100+1000/3*0.001*(double)caliber;
    printf("Caliber: %i mm\n",caliber);
    printf("Shell weight: %i kg\n",shell_weight);
    printf("Air drag: %.2lf\n",air_drag);
    printf("Initial velocity: %i m/s\n",initial_velocity);
   
    

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
        if (fabs(x-range)/(double)range < 0.01){
            launching_angle=0.01*i;
            v = sqrt(vx*vx+vy*vy);
            fall_angle=atan(fabs(vy)/vx)*180/pi;
            goto end;
        }
    } 
    end:
        penetration=Krupp_calculation*pow(v,1.1)*pow(shell_weight,0.55)/pow((double)caliber,0.65);
		verti_pen = penetration * sin(fall_angle*pi/180.0);
        printf("Range: %i m\n",range);
        printf("Velocity: %.2lf m/s\n",v);
        printf("Angle: %.2lf\n",launching_angle);
		printf("Falling Angle: %.2lf\n",fall_angle);
        printf("Penetration at this range: %.2lf mm\n",penetration);
		if (HMS==true){
			if (fall_angle<15){
				printf("Vertical Penetration: Bounce\n");
			}else{
				printf("Vertical Peneration: %.2lf mm\n",verti_pen);
			}			
		}else if (USN == true){
			if (fall_angle<23.5){
				printf("Vertical Penetration: Bounce\n");
			}else{
				printf("Vertical Peneration: %.2lf mm\n",verti_pen);
			}			
		}else{
			if (fall_angle < 30){
				printf("Vertical Penetration: Bounce\n");
			}else{
				printf("Vertical Penetration: %.2lf mm\n",verti_pen);
			}
			
		}
		system("pause");
}

int main()
{
	printf("Ship Name: \n");
	get_Datas();
    printf("Range: \n");
    scanf("%i",&range);
    Calculate_Projectile();
}