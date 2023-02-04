#include<stdio.h>
#include<math.h>

float bill (float unit)
{
    float a=4.40, b=6.01, c=6.30, d=6.66, e=10.44, f=12.03;
    float primary_bill;
    if (unit <=75)
    {
        primary_bill = unit*a;
    }

    else if (unit <= 200)
    {
        primary_bill = (75*a + (unit-75)*b );
    }

    else if (unit <=300)
    {
        primary_bill = (75*a + 125*b + (unit-200)*c );
    }

    else if (unit <=400)
    {
        primary_bill = (75*a + 125*b + 100*c + (unit-300)*d );
    }

    else if (unit <=600)
    {
        primary_bill = (75*a + 125*b + 100*c + 100*d + (unit-400)*e );
    }

    else 
    {
        primary_bill = (75*a + 125*b + 100*c + 100*d + 200*e + (unit-600)*f );
    }

    float secondary_bill=primary_bill+70;
    float tertiary_bill = secondary_bill+secondary_bill*0.05;
    float final_bill = tertiary_bill + tertiary_bill*0.01;  //for bkash payment

    return final_bill;
}


int main ()
{
    printf("How many households utilized the water facility? \n(Input 0 if water bill is not a concern.\nInput 100 to manually input water bill per house.)\n");
    float household, water_last, water_prev, water_bill, per_water_bill;
    scanf(" %f", &household);
    if (household==0) 
    {
        water_bill=0; per_water_bill=0; water_last=water_prev=0;
    }
    else if (household==100) 
    {
        printf("\nManually input Water Bill Per House: ") ;
        scanf(" %f", &per_water_bill);
        water_bill=0; water_last=water_prev=0;
    }
    else 
    { 
        printf("\nWater Meter current reading: ");
        scanf(" %f", &water_last);
        printf("\nWater Meter last reading: ");
        scanf(" %f", &water_prev);
        water_bill = bill(water_last-water_prev);
        per_water_bill = water_bill/household;
    }
  
    
    printf("\nWATER METER UNIT USED %.2f\nWATER METER BILL %.2f\nWATER BILL PER HOUSE %.2f\n\n", water_last-water_prev, water_bill, per_water_bill); 
    int t = 100;
    while (t--)
    {
        printf("\nHouse Meter current reading: ");
        float house_last;
        scanf(" %f", &house_last);
        printf("\nHouse Meter last reading: ");
        float house_prev;
        scanf(" %f", &house_prev);
        float house_bill = bill(house_last-house_prev);
        printf("\nHOUSE METER UNIT USED %.2f\nHOUSE METER BILL INCLUDING WATER BILL %.2f\n\n", house_last-house_prev, house_bill+per_water_bill);
    }

    return 0;
}
