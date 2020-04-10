    #include "TXLib.h"
    #include <cmath>
    #include "string.h"
    #include <iostream> //нужен для вывода строк "cout<<"
    #include "conio.h" //нужен намеренно для "getche()", а не "cin>>"
    #include "windows.h"
    #include <cstdlib>
    #include<string>
    #include<sstream>


    using namespace std;

    int sizeX;
    int sizeY;
    COLORREF color = TX_BLACK;
    bool motion = false;

    void linerMash(int k){
    txSetColor(TX_GRAY, 1.25);
    int i=sizeX/4;
    int i2 = sizeY/2;

        while(i>=0){

            txLine(i, 0, i, sizeY);
            i-=k;



        }


        while(i2>=0){

            txLine(0, i2, sizeX/2, i2);
            i2-=k;

        }
        i2 = sizeY/2;
        i=sizeX/4;

        while(i<=sizeX/2){

            txLine(i, 0, i, sizeY);
            i+=k;

        }


        i2=sizeY/2;

        while(i2<=sizeY){

            txLine(0, i2, sizeX/2, i2);

            i2+=k;

        }

        /*i=450;
        while(i>=0){

            txLine(i, 450, i, 900);
            txLine(450, i, 900, i);
            i-=k;

        }

        i=450;

        while(i<=900){

            txLine(i, 0, i, 450);
            txLine(0, i, 450, i);
            i+=k;

        }*/


    txSetColor(TX_RED, 2.5);
    txLine(0, sizeY/2, sizeX/2, sizeY/2);
    txLine(sizeX/4, 0, sizeX/4, sizeY);


    }

    void parabola(float a, float b, float c, float Coefficient){

    float y, y1;
    int X = sizeX/4;
    int Y = sizeY/2;

        float i;

        for(i=(-b)/(2*a); i<X/(Coefficient); i+=(1/Coefficient*2)){

            y = -((a*((i)*(i))+b*i+c)*(Coefficient));
            // = -((a*((i-b)*(i-b))+c)*Coefficient);
            y1 = -((a*((i+1)*(i+1))+b*(i+1)+c)*(Coefficient));

            txSetColor(color, 3);
            txLine(i*(Coefficient)+sizeX/4, y1+Y, i*(Coefficient)+sizeX/4, y+Y);
        }


        for(i=(-b)/(2*a)-(1/Coefficient*2); i>=0-X; i-=(1/Coefficient*2)){

            y = -((a*((i)*(i))+b*i+c)*(Coefficient));
            // = -((a*((i-b)*(i-b))+c)*Coefficient);
            y1 = -((a*((i+1)*(i+1))+b*(i+1)+c)*(Coefficient));

            txSetColor(color, 3);
            txLine(i*(Coefficient)+sizeX/4, y1+Y, i*(Coefficient)+sizeX/4, y+Y);


        }



    }

    void linear(float a, float b, float Coefficient){

    float i;
    float y, y1;
    int X = sizeX/4;
    int Y = sizeY/2;



    for(i=0-X; i<X/(Coefficient); i+=(2/Coefficient)){

    y = (a*i-b)*(Coefficient);
    y1 = (a*(i+1)-b)*(Coefficient);

    txSetColor(color, 4);
    txLine(i*(Coefficient)+sizeX/4, y1+Y, i*(Coefficient)+sizeX/4, y+Y);
    }

    }

    void modul(float a, float b, float Coefficient){
    //y=|kx+b|
    float i;
    float y, y1;
    int X = sizeX/4;
    int Y = sizeY/2;

    //b = b-15;

    for(i=0-X; i<=X/(Coefficient); i+=(1.2/Coefficient)){
    if(i>0 || i==0){
    y = (-a*i-b)*(Coefficient);
    y1 = (-a*(i+(1.5/Coefficient))-b)*(Coefficient);

    }else if(i<0 || i==0){

    y = (a*i-b)*(Coefficient);
    y1 = (a*(i+(1.2/Coefficient))-b)*(Coefficient);

    }


    txSetColor(color, 2);
    txLine(i*(Coefficient)+sizeX/4, y1+Y, i*(Coefficient)+sizeX/4, y+Y);
    }




    }

    void circleFunction(float a, float b, float R, float Coefficient){


    int X = sizeX/4;
    int Y = sizeY/2;


    txSetColor(color, 2);



    txArc(X+(a*Coefficient)-R*Coefficient, Y-(b*Coefficient)-R*Coefficient, X+(a*Coefficient)+R*Coefficient, Y-(b*Coefficient)+R*Coefficient, 0, 360);


    }

    void powFun(float a, float b, float Coefficient){


    float y, y1;
    int X = sizeX/4;
    int Y = sizeY/2;

    float i;


    for(i = 0; i<=X/(Coefficient)/a; i+=(1/Coefficient*2)){

    y=-pow(a,i)-b*10;
    y1=-pow(a,(i+1))-b*10;


    txSetColor(color, 2);
    txLine(i*(Coefficient)+sizeX/4, y1+Y, i*(Coefficient)+sizeX/4, y+Y);

    }




    }

    void differ(float* dif, int pluss, int minuss, float* Coefficient, float stop, float stop_down, float downZero, float inZero, int Z){

        if(GetAsyncKeyState(pluss)){
        (*dif)+=(*Coefficient);
        if((*dif)>stop)(*dif)=stop;
        }
        if(GetAsyncKeyState(minuss)){
        (*dif)-=(*Coefficient);
        if((*dif)<stop_down)(*dif)=stop_down;
        }
        if((*dif)<=downZero && Z*(*dif)>0)(*dif) = -inZero;
        if((*dif)>=-downZero && Z*(*dif)<0)(*dif) = inZero;

    }

    void drawButtons(int x, int y, int x2, int y2, int Red, int Green, int Blue, string textt){

    txSetFillColor(RGB(Red, Green, Blue));
    txSetColor(RGB(Red-10, Green-10, Blue-10), 2);
    POINT ButtoN[4] = { {x, y}, {x, y2}, {x2, y2}, {x2, y} };
    txPolygon (ButtoN, 4);

        char nm[100];
        strcpy(nm,textt.c_str());
        txSetColor(TX_WHITE);
        txSelectFont ("Arial", 30, 0, FW_BOLD);
        txDrawText(x+5, y2-10, x2+20, y, nm, DT_CENTER);



    }

    bool Buttons(int x, int y, int x2, int y2, int Red, int Green, int Blue, string textt){
        bool K=false;
        drawButtons(x, y, x2, y2, Red, Green, Blue, textt);
        if(txMouseX()>=x && txMouseX()<=x+200+25 && txMouseY()>=y-50 && txMouseY()<=y ){

        drawButtons(x, y, x2, y2, Red+30, Green+30, Blue+30, textt);

            if(GetAsyncKeyState (0x01)){
                K=true;
            }

        }
        return(K);
    }

    bool Colors(int x, int y, COLORREF color){
        bool K=false;
        txSetColor(color);
        txSetFillColor(color);

        txRectangle(x, y, x+20, y+20);
        if(txMouseX()>=x && txMouseX()<=x+20 && txMouseY()>=y && txMouseY()<=y+20 ){

            if(GetAsyncKeyState (0x01)){
                K=true;
            }

        }
        return(K);
    }



    void UI(){


    txSetColor(TX_GRAY);
    txSetFillColour(TX_GRAY);
    txRectangle(sizeX/2, 0, sizeX, sizeY);

    //Buttons(int x, int y, int x2, int y2, int Red, int Green, int Blue, string textt);

    txSetColor(TX_BLACK);
    txSelectFont ("Arial", 40, 0, FW_BOLD);

    txTextOut(sizeX/2+10, 10, "For F1 to F5 to change function");
    txSetColor(TX_BLACK);
    txSelectFont ("Arial", 30, 0, FW_BOLD);
    txTextOut(sizeX/2+10, sizeY-120, "Tap \"HOME\" to on, tap \"END\" to off manual control");
    txTextOut(sizeX/2+10, sizeY-60, "Manual control:");

    if(motion){
    txSetColor(TX_GREEN);
    txTextOut(sizeX/2+10+150+50, sizeY-60, "ON");
    }else{
    txSetColor(TX_RED);
    txTextOut(sizeX/2+10+150+50, sizeY-60, "OFF");
    }

    txSetColor(TX_BLACK);
    txSelectFont ("Arial", 40, 0, FW_BOLD);

    txTextOut(sizeX/2+10, 400, "Select a color:");
    if(Colors(sizeX/2+10+100+100+50-20+10, 410, TX_BLACK)){

    color = TX_BLACK;

    }
    if(Colors(sizeX/2+10+100+100+50+10, 410, TX_RED)){
    color = TX_RED;
    }
    if(Colors(sizeX/2+10+100+100+50+20*1+10, 410, TX_ORANGE)){
    color = TX_ORANGE;
    }
    if(Colors(sizeX/2+10+100+100+50+20*2+10, 410, TX_YELLOW)){
    color = TX_YELLOW;
    }
    if(Colors(sizeX/2+10+100+100+50+20*3+10, 410, TX_GREEN)){
    color = TX_GREEN;
    }
    if(Colors(sizeX/2+10+100+100+50+20*4+10, 410, TX_BLUE)){
    color = TX_BLUE;
    }

    txSetColor(TX_BLACK);
    txTextOut(sizeX/2+10, 450, "Your color:");
    Colors(sizeX/2+10+100+100-20+10, 460, color);










    }

    void drawNumeric(float a, int x1, int y1, int x2, int y2){

        float integer = a;
        string str;
        ostringstream stream;
        stream << integer;
        str = stream.str();

        char nm[100];
        strcpy(nm,str.c_str());
        txSetColor(TX_BLACK);
        txSelectFont ("Arial", 40, 0, FW_BOLD);
        txDrawText(x1, y1, x2, y2, nm, DT_LEFT);


    }

    void enterToWrite(int x1, int y1, int x2, int y2, string para, float* param){



    if(txMouseX()>=x1 && txMouseX()<=x2 && txMouseY()>=y1 && txMouseY()<=y2){
            if(GetAsyncKeyState (0x01)){

                    float integer = (*param);
                    string str;
                    ostringstream stream;
                    stream << integer;
                    str = stream.str();

                    char nm1[100];
                    strcpy(nm1,str.c_str());



                    string pa=para;
                    char Display[100]="Значение параметра ";
                    char nm[100];
                    strcpy(nm,pa.c_str());
                    txSetColor(TX_WHITE);

                    strcat (Display, nm);

                    const char* name = txInputBox (Display, "Изменение параметра", nm1);

                    float temp = atof(name);

                    if(temp!=NULL){
                    (*param)=temp;

                    }else{

                    (*param)=(*param);
                    }


            }

        }
    }


    int main(){

        cout << "Put your 'X size' and 'Y size' of screen\n";
        cin >> sizeX >> sizeY;

        txCreateWindow (sizeX, sizeY);
        txClear();

        float k  = 10;
        float coef1 = 0.01;//0.001

        float coef2 = 0.5;
        float coef3 = 0.1;
        float coef4 = 0.8;

        int functions = -1;


        float a=2, b=0, c=0;

        int a1=NULL, a2=NULL, b1=NULL, b2=NULL, c1=NULL, c2=NULL;



        txBegin();


        bool k0, k1, k2, k3, k4;

        while(!GetAsyncKeyState(0x1B)){


        txSetColor(TX_WHITE);
        txSetFillColour(TX_WHITE);
        txRectangle(0, 0, sizeX/2, sizeY);
        linerMash(k);
        differ(&k, 0xA1, 0xA3, &coef2, 28, 8, 0, 0, 1);

        if(GetAsyncKeyState(0x70)){
        functions = 0;
        }else if(GetAsyncKeyState(0x71)){
        functions = 1;
        }else if(GetAsyncKeyState(0x72)){
        functions = 2;
        }else if(GetAsyncKeyState(0x73)){
        functions = 3;
        }else if(GetAsyncKeyState(0x74)){
        functions = 4;
        }

        if(GetAsyncKeyState (0x24)){
        motion = true;
        }
        if(GetAsyncKeyState (0x23)){
            motion = false;
        }

        if(motion){
        a1=0x51;
         a2=0x41;
          b1=0x57;
           b2=0x53;
            c1=0x45;
             c2=0x44;

        }else{
        a1=NULL;
         a2=NULL;
          b1=NULL;
           b2=NULL;
            c1=NULL;
             c2=NULL;
        }



        //functions = 2 ;


        switch(functions){


            case 0:
                if(k0){
                    k0 = false;
                    k1=true;
                    k2=true;
                    k3=true;
                    k4=true;

                    a = 2;
                    b = 0;
                    c = 0.0;

                }
                parabola(a, b-(a/1.5), c, k);
                differ(&a, a1, a2, &coef1, 4, -4, 0.01, 0.02, 1);//&coef1, 5, -5, 0.01, 0.02
                differ(&b, b1, b2, &coef3, 20, -20, 0, 0, 1);
                differ(&c, c1, c2, &coef2, 10, -10, 0, 0, 1);
                UI();

                        txSetColor(TX_BLACK);
                        txSetFillColor(TX_WHITE);

                        txRectangle(920, 125, 1080, 180);
                        drawNumeric(a, 920, 125, 1080, 180);
                        enterToWrite(920, 125, 1080, 180, "A", &a);
                        txTextOut(700, 135, "Param \"A\"");

                        if(motion){
                        txSetColor(TX_BLACK);
                        txSelectFont ("Arial", 20, 0, FW_BOLD);
                        txTextOut(1090, 135, "\"Q\" - up, \"A\" - down");
                        txSetColor(TX_BLACK);
                        txSelectFont ("Arial", 20, 0, FW_BOLD);
                        txTextOut(1090, 235, "\"W\" - up, \"S\" - down");
                        txSetColor(TX_BLACK);
                        txSelectFont ("Arial", 20, 0, FW_BOLD);
                        txTextOut(1090, 335, "\"E\" - up, \"D\" - down");
                        }

                        txRectangle(920, 225, 1080, 280);
                        drawNumeric(b, 920, 225, 1080, 280);
                        enterToWrite(920, 225, 1080, 280, "B", &b);
                        txTextOut(700, 235, "Param \"B\"");


                        txRectangle(920, 325, 1080, 380);
                        drawNumeric(c, 920, 325, 1080, 380);
                        enterToWrite(920, 325, 1080, 380, "C", &c);
                        txTextOut(700, 335, "Param \"C\"");


                                txSetColor(TX_BLUE);
                                txSelectFont ("Arial", 40, 0, FW_BOLD);
                        txTextOut(sizeX/2+10, 525, "Parabola: y = A*(x^2)\+B*x\+C");


                break;

            case 1:

                if(k1){
                    k1 = false;
                    k0=true;
                    k2=true;
                    k3=true;
                    k4=true;

                    a = 2;
                    b = 0;
                    c = 1;


                }
                linear(a, b, k);
                differ(&a, a1, a2, &coef3, 20, -20, -25, -24, -1);
                differ(&b, b1, b2, &coef2, 30, -30, 0, 0, 1);
                UI();
                        txSetColor(TX_BLACK);
                        txSetFillColor(TX_WHITE);

                        txRectangle(920, 125, 1080, 180);
                        drawNumeric(a, 920, 125, 1080, 180);
                        enterToWrite(920, 125, 1080, 180, "A", &a);
                        txTextOut(700, 135, "Param \"A\"");

                        if(motion){
                        txSetColor(TX_BLACK);
                        txSelectFont ("Arial", 20, 0, FW_BOLD);
                        txTextOut(1090, 135, "\"Q\" - up, \"A\" - down");
                        txSetColor(TX_BLACK);
                        txSelectFont ("Arial", 20, 0, FW_BOLD);
                        txTextOut(1090, 235, "\"W\" - up, \"S\" - down");
                        }

                        txRectangle(920, 225, 1080, 280);
                        drawNumeric(b, 920, 225, 1080, 280);
                        enterToWrite(920, 225, 1080, 280, "B", &b);
                        txTextOut(700, 235, "Param \"B\"");


                                txSetColor(TX_BLUE);
                                txSelectFont ("Arial", 40, 0, FW_BOLD);
                        txTextOut(sizeX/2+10, 525, "Linear: y = A*x\+B");

                break;

            case 2:

                if(k2){
                    k2 = false;
                    k1=true;
                    k0=true;
                    k3=true;
                    k4=true;

                    a = 0;
                    b = 0;
                    c = 5;

                }

                circleFunction(a, b, c, k);
                differ(&a, a1, a2, &coef3, 8, -8, -8, -7, -1);//&coef1, 5, -5, 0.01, 0.02*/
                differ(&b, b1, b2, &coef3, 8, -8, -8, -7, -1);
                differ(&c, c1, c2, &coef2, 20, -20, 0, 0, 1);
                UI();
                        txSetColor(TX_BLACK);
                        txSetFillColor(TX_WHITE);

                        txRectangle(920, 125, 1080, 180);
                        drawNumeric(a, 920, 125, 1080, 180);
                        enterToWrite(920, 125, 1080, 180, "A", &a);
                        txTextOut(700, 135, "Param \"A\"");

                        if(motion){
                        txSetColor(TX_BLACK);
                        txSelectFont ("Arial", 20, 0, FW_BOLD);
                        txTextOut(1090, 135, "\"Q\" - up, \"A\" - down");

                        txSetColor(TX_BLACK);
                        txSelectFont ("Arial", 20, 0, FW_BOLD);
                        txTextOut(1090, 235, "\"W\" - up, \"S\" - down");

                        txSetColor(TX_BLACK);
                        txSelectFont ("Arial", 20, 0, FW_BOLD);
                        txTextOut(1090, 335, "\"E\" - up, \"D\" - down");
                        }

                        txRectangle(920, 225, 1080, 280);
                        drawNumeric(b, 920, 225, 1080, 280);
                        enterToWrite(920, 225, 1080, 280, "B", &b);
                        txTextOut(700, 235, "Param \"B\"");

                        txRectangle(920, 325, 1080, 380);
                        drawNumeric(c, 920, 325, 1080, 380);
                        enterToWrite(920, 325, 1080, 380, "R", &c);
                        txTextOut(700, 335, "Param \"R\"");


                                txSetColor(TX_BLUE);
                                txSelectFont ("Arial", 40, 0, FW_BOLD);

                        txTextOut(sizeX/2+10, 525, "Circle: R^2 = (x\-a)^2+(y\-b)^2");

                break;

            case 3:

                if(k3){
                    k3 = false;
                    k1=true;
                    k2=true;
                    k0=true;
                    k4=true;

                    a = 1;
                    b = 0;
                    c = 0;

                }

                modul(a, b, k);
                differ(&a, a1, a2, &coef3, 15, -15, -15, -14, -1);
                differ(&b, b1, b2, &coef2, 20, -20, 0, 0, 1);
                UI();
                        txSetColor(TX_BLACK);
                        txSetFillColor(TX_WHITE);

                        txRectangle(920, 125, 1080, 180);
                        drawNumeric(a, 920, 125, 1080, 180);
                        enterToWrite(920, 125, 1080, 180, "A", &a);
                        txTextOut(700, 135, "Param \"A\"");

                        if(motion){
                        txSetColor(TX_BLACK);
                        txSelectFont ("Arial", 20, 0, FW_BOLD);
                        txTextOut(1090, 135, "\"Q\" - up, \"A\" - down");

                        txSetColor(TX_BLACK);
                        txSelectFont ("Arial", 20, 0, FW_BOLD);
                        txTextOut(1090, 235, "\"W\" - up, \"S\" - down");
                        }

                        txRectangle(920, 225, 1080, 280);
                        drawNumeric(b, 920, 225, 1080, 280);
                        enterToWrite(920, 225, 1080, 280, "B", &b);
                        txTextOut(700, 235, "Param \"B\"");


                                txSetColor(TX_BLUE);
                                txSelectFont ("Arial", 40, 0, FW_BOLD);
                        txTextOut(sizeX/2+10, 525, "Modul: y = |A*x\+B|");

                break;

            case 4:

                if(k4){
                    k4 = false;
                    k1=true;
                    k2=true;
                    k3=true;
                    k0=true;

                    a = 5;
                    b = 0;
                    c = 0;

                }

                powFun(a, b, k);
                differ(&a, a1, a2, &coef3, 20, 1, 0, 0, 1);
                differ(&b, b1, b2, &coef2, 20, -20, 0, 0, 1);
                UI();
                        txSetColor(TX_BLACK);
                        txSetFillColor(TX_WHITE);

                        txRectangle(920, 125, 1080, 180);
                        drawNumeric(a, 920, 125, 1080, 180);
                        enterToWrite(920, 125, 1080, 180, "A", &a);
                        txTextOut(700, 135, "Param \"A\"");
                        if(motion){
                        txSetColor(TX_BLACK);
                        txSelectFont ("Arial", 20, 0, FW_BOLD);
                        txTextOut(1090, 135, "\"Q\" - up, \"A\" - down");

                        txSetColor(TX_BLACK);
                        txSelectFont ("Arial", 20, 0, FW_BOLD);
                        txTextOut(1090, 235, "\"W\" - up, \"S\" - down");
                        }

                        txRectangle(920, 225, 1080, 280);
                        drawNumeric(b, 920, 225, 1080, 280);
                        enterToWrite(920, 225, 1080, 280, "B", &b);
                        txTextOut(700, 235, "Param \"B\"");

                                txSetColor(TX_BLUE);
                                txSelectFont ("Arial", 40, 0, FW_BOLD);
                        txTextOut(sizeX/2+10, 525, "Powered: y = A^x");

                break;

            default:
                    UI();
                    break;

        }


        /*differ(&b, 0x57, 0x53, &coef3, 15, -15, 0, 0, 1);
        differ(&c, 0x26, 0x28, &coef2, 8, -8, 0, 0, 1);*/



        txSetColor(TX_GREEN, 10);
        txSetFillColor(NULL);




        /*integer = (-b)/(2*a);
        string str3;
        ostringstream stream3;
        stream3 << integer;
        str3 = stream3.str();
        char nm3[100];
        strcpy(nm3,str3.c_str());
        txSetColor(TX_WHITE);
        txSelectFont ("Arial", 40, 0, FW_BOLD);
        txDrawText(920, 300, 1080, 350, nm3, DT_LEFT);*/


        txSetColor(NULL);
        txSetFillColor(NULL);
        txSleep(16);
        txClear();


        }
        txEnd();
        txDisableAutoPause();

    }


