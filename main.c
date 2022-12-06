#include<stdio.h>
#include<math.h>

float bill (float unit)
{
    float primary_bill;
    if (unit <=75)
    {
        primary_bill = unit*4.19;
    }

    else if (unit <= 200)
    {
        primary_bill = (75*4.19 + (unit-75)*5.72 );
    }

    else if (unit <=300)
    {
        primary_bill = (75*4.19 + 125*5.72 + (unit-200)*6.00 );
    }

    else if (unit <=400)
    {
        primary_bill = (75*4.19 + 125*5.72 + 100*6.00 + (unit-300)*6.34 );
    }

    else if (unit <=400)
    {
        primary_bill = (75*4.19 + 125*5.72 + 100*6.00 + (unit-300)*6.34 );
    }

    else if (unit <=600)
    {
        primary_bill = (75*4.19 + 125*5.72 + 100*6.00 + 100*6.34 + (unit-400)*9.94 );
    }

    else 
    {
        primary_bill = (75*4.19 + 125*5.72 + 100*6.00 + 100*6.34 + 200*9.94 + (unit-600)*11.46 );
    }

    float secondary_bill=primary_bill+60;
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