#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char ship_name;
int caliber;
int initial_velocity;
int krupp;
int shell_weight;
double air_drag;
bool USN;
bool HMS;

void get_ship_data(char ship_name);
void ask_for_shell_para();
void display_ship_data(char ship_name, int caliber,int initial_velocity,int krupp,int shell_weight, double air_drag, bool USN,bool HMS);
void calculate_penetration(char ship_name, int caliber,int initial_velocity,int krupp,int shell_weight, double air_drag, bool USN,bool HMS);

int main(){
	int function_choice;
	int name;
	printf("World of Warships AP Projectile Tool\n");
	printf("----------------------------------------\n");
	printf("Please choose the function you want\n");
	printf("1. Calculate the AP penetration of an exisiting ship in the game\n");
	printf("2. Calculate the AP penetration of any shells with parameter given by user\n");
	printf("3. Show the shell parameter of an exisiting ship in the game\n");
	printf("Now your choice:\n")
	scanf("%i",&function_choice);
	switch(function_choice){
		case 1:
			scanf("%c",&name);
			get_ship_data(name);
			calculate_penetration(ship_name,caliber,initial_velocity,krupp,shell_weight,air_drag,USN,HMS);
			break;
		case 2:
			ask_for_shell_para();
			calculate_penetration(ship_name,caliber,initial_velocity,krupp,shell_weight,air_drag,USN,HMS);
			break;
		case 3:
			get_ship_data(name);
			display_ship_data(ship_name,caliber,initial_velocity,krupp,shell_weight,air_drag,USN,HMS);
			case;
	}	
}

void get_ship_data(char ship_name_pr){
	if (strcmp(ship_name,"USN_DD")==0){
        caliber = 127;
        initial_velocity = 792;
        Krupp = 2598;
        shell_weight = 25;
        air_drag = 0.347;
		USN = 0;
		HMS = 0;
    }else if(strcmp(ship_name,"Sampson")==0){
		caliber = 102;
		initial_velocity = 884;
        Krupp =1451;
        shell_weight = 15;
        air_drag = 0.33;
		USN = 0;
		HMS = 0;
    }else if(strcmp(ship_name,"Smith")==0){
		caliber = 76;
		initial_velocity = 823;
        Krupp =2480;
        shell_weight = 6;
        air_drag = 0.47;
		USN = 0;
		HMS = 0;
    }else if(strcmp(ship_name,"Wickes")==0){
		caliber = 102;
		initial_velocity = 884;
        Krupp =1451;
        shell_weight = 15;
        air_drag = 0.33;
		USN = 0;
		HMS = 0;
    }else if(strcmp(ship_name,"Clemson")==0){
		caliber = 102;
		initial_velocity = 884;
        Krupp =1451;
        shell_weight = 15;
        air_drag = 0.33;
		USN = 0;
		HMS = 0;
    }else if(strcmp(ship_name,"Nicolas_Stock")==0){
		caliber = 127;
		initial_velocity = 960;
        Krupp =1400;
        shell_weight = 23;
        air_drag = 0.36;
		USN = 0;
		HMS = 0;
    }else if(strcmp(ship_name,"Omaha")==0){
		caliber = 152;
		initial_velocity = 914;
        Krupp =1772;
        shell_weight = 48;
        air_drag = 0.3164;
		USN = 0;
		HMS = 0;
    }else if(strcmp(ship_name,"Cleveland")==0){
		caliber = 152;
		initial_velocity = 762;
        Krupp =2445;
        shell_weight = 59;
        air_drag = 0.322;
		USN = 0;
		HMS = 0;
    }else if (strcmp(ship_name,"USN_203mm")==0){
        caliber = 203;
		initial_velocity = 853;
        Krupp =2846;
        shell_weight = 118;
        air_drag = 0.321;
		USN = true;
		HMS = 0;
    }else if (strcmp(ship_name,"USN_203mm_Superheavy")==0){
        caliber = 203;
        initial_velocity = 762;
        Krupp = 2919;
        shell_weight = 152;
        air_drag = 0.356;
		USN=true;
		HMS = 0;
    }else if(strcmp(ship_name,"South_Carolina")==0){
		caliber = 305;
		initial_velocity = 823;
        Krupp =2408;
        shell_weight = 395;
        air_drag = 0.435;
		USN = 0;
		HMS = 0;
    }else if(strcmp(ship_name,"Wyoming")==0){
		caliber = 305;
		initial_velocity = 884;
        Krupp =2523;
        shell_weight = 395;
        air_drag = 0.337;
		USN = 0;
		HMS = 0;
    }else if(strcmp(ship_name,"Arizona")==0){
		caliber = 356;
		initial_velocity = 792;
        Krupp =2604;
        shell_weight = 680;
        air_drag = 0.332;
		USN = 0;
		HMS = 0;
    }else if (strcmp(ship_name,"USN_356mm")==0){
        caliber = 356;
        initial_velocity = 792;
        Krupp =2604;
        shell_weight = 680;
        air_drag = 0.332;
		USN = 0;
		HMS = 0;
    }else if (strcmp(ship_name,"New_York_A")==0){
        caliber =356;
        initial_velocity = 792;
        Krupp =1603;
        shell_weight = 635;
        air_drag = 0.366;
		USN = 0;
		HMS = 0;
    }else if (strcmp(ship_name,"Colorado")==0){
        caliber =406;
        initial_velocity =768;
        Krupp =2636;
        shell_weight =1068;
        air_drag =0.336;
		USN = 0;
		HMS = 0;
    }else if (strcmp(ship_name,"Mk6")==0){
        caliber = 406;
        initial_velocity = 701;
        Krupp =2598;
        shell_weight = 1225;
        air_drag = 0.352;
		USN=true;
		USN = 0;
		HMS = 0;
    }else if (strcmp(ship_name,"Mk7")==0){
        caliber =406;
        initial_velocity = 762;
        Krupp =2520;
        shell_weight =1225;
        air_drag =0.352;
		USN=true;
		HMS = 0;
    }else if (strcmp(ship_name,"IJN_140mm")==0){
        caliber = 140;
        initial_velocity = 850;
        Krupp =1794;
        shell_weight = 38;
        air_drag = 0.3696;
		USN = 0;
		HMS = 0;
    }else if (strcmp(ship_name,"IJN_CA_Tier_5-9")==0){
        caliber =203;
        initial_velocity =840;
        Krupp =2468;
        shell_weight =126;
        air_drag =0.337;
		USN = 0;
		HMS = 0;
    }else if (strcmp(ship_name,"Zao")==0){
        caliber = 203;
        initial_velocity = 920;
        Krupp =2468;
        shell_weight = 155;
        air_drag = 0.337;
		USN = 0;
		HMS = 0;
    }else if (strcmp(ship_name,"Mogami")==0){
		caliber = 155;
        initial_velocity = 56;
        Krupp =2429;
        shell_weight = 925;
        air_drag = 0.335;
		USN = 0;
		HMS = 0;
    }else if(strcmp(ship_name,"Umikaze")==0){
		caliber = 120;
		initial_velocity = 660;
        Krupp =1750;
        shell_weight = 20;
        air_drag = 0.331;
		USN = 0;
		HMS = 0;
    }else if(strcmp(ship_name,"Tachibana")==0){
		caliber = 76;
		initial_velocity = 690;
        Krupp =1250;
        shell_weight = 7;
        air_drag = 0.35;
		USN = 0;
		HMS = 0;
    }else if(strcmp(ship_name,"Isokaze")==0){
		caliber = 120;
		initial_velocity = 660;
        Krupp =1750;
        shell_weight = 20;
        air_drag = 0.331;
		USN = 0;
		HMS = 0;
    }else if(strcmp(ship_name,"Minekaze")==0){
		caliber = 120;
		initial_velocity = 825;
        Krupp =1750;
        shell_weight = 20;
        air_drag = 0.331;
		USN = 0;
		HMS = 0;
    }else if (strcmp(ship_name,"IJN_127mm")==0){
        caliber = 127;
        initial_velocity = 915;
        Krupp = 2266;
        shell_weight = 23;
        air_drag = 0.334;
		USN = 0;
		HMS = 0;
    }else if (strcmp(ship_name,"Akizuki")==0){
        caliber = 100;
        initial_velocity = 1000;
        Krupp =2154;
        shell_weight = 13;
        air_drag = 0.3137;
		USN = 0;
		HMS = 0;
    }else if (strcmp(ship_name,"IJN_356mm")==0){
        caliber = 356;
        initial_velocity = 775;
        Krupp =2657;
        shell_weight = 674;
        air_drag = 0.331;
		USN = 0;
		HMS = 0;
    }else if (strcmp(ship_name,"IJN_410mm")==0){
        caliber = 410;
        initial_velocity = 775;
        Krupp =2711;
        shell_weight = 1020;
        air_drag = 0.365;
		USN = 0;
		HMS = 0;
    }else if (strcmp(ship_name,"Izumo")==0){
        caliber = 410;
        initial_velocity = 806;
        Krupp =2711;
        shell_weight = 1020;
        air_drag = 0.365;
		USN = 0;
		HMS = 0;
    }else if (strcmp(ship_name,"Yamato")==0){
        caliber =460;
        initial_velocity =780;
        Krupp =2574;
        shell_weight = 1460;
        air_drag = 0.292;
		USN = 0;
		HMS = 0;
    }else if(strcmp(ship_name,"Storozhevoi")==0){
		caliber = 120;
		initial_velocity = 823;
        Krupp =1488;
        shell_weight = 18;
        air_drag = 0.3756;
		USN = 0;
		HMS = 0;
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
	
}