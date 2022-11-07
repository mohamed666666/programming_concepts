#include <iostream>

using namespace std;



struct ShapeVtable;


struct Shape{
   ShapeVtable* vtable;
};


struct ShapeVtable{
    double (*Area)(Shape*);
    void (*Info)(Shape*);
};




double GetArea(Shape*s){

    double area= s->vtable->Area(s);
   // cout<<"Area"<<area<<endl;
    return area;
}

void PrintInfo(Shape*s){
    s->vtable->Info(s);
}





struct Circle{
    Shape parent;
    double radis;
};


double CircleArea(Circle* c){
    return (c->radis)*3.14;
}

void CircleInfo(Circle *c){
    cout<<"Circle radius :"<<c->radis<<endl;

}


ShapeVtable Circlevtable={
    (double(*)(Shape*)) CircleArea,
    (void(*)(Shape*)) CircleInfo
};




//Rectangle

struct Rectangle{
    Shape parent;

    double width;
    double hight;

};



double RectangleArea(Rectangle* r){
    return (r->hight )*(r->width);

}

void RectangleInfo(Rectangle *r){
    cout<<"The Rectangle width & hight Are:"<<r->width<<" & "<<r->hight<<endl;
}


ShapeVtable Rectanglevtable={
    (double(*)(Shape*)) RectangleArea,
    (void(*)(Shape*)) RectangleInfo
};




//    Ellipsee
struct Ellipse {
    Shape parent;

    double a;
    double b;

};

double EllipseArea(Ellipse* e){
    return (e->a)*(e->b)*(3.14);
}


void EllipseInfo(Ellipse * e){
    cout<<"Ellipse Informations :"<<e->a<<" "<<e->b<<endl;

}

ShapeVtable Ellipsevtable={
    (double(*)(Shape*))EllipseArea,
    (void (*)(Shape*))EllipseInfo
};







void CircleInitialize(Circle *c,double rad){
    //struct Circle c;
    c->parent.vtable=&Circlevtable;
    c->radis=rad;
    //return *c;
}

void RectangleInitialize(Rectangle* r, double w , double h){
    r->parent.vtable=&Rectanglevtable;
    r->width=w;
    r->hight=h;
}

void EllipseInitialize( Ellipse *e, double a, double b){
    e->parent.vtable=&Ellipsevtable;
    e->a=a;
    e->b=b;

}








int main()
{


/*
    struct Shape s={10,20};





    cout << "width :"<<s.angels[0]<<" hight :"<< s.angels[1] << endl;
*/
   /* struct Circle circle;

    Shape* shapes[3];
    shapes[0]=(Shape*)&circle ;
    */

    Circle circle;
    CircleInitialize(&circle, 10.0);





    Rectangle rectangle;
    RectangleInitialize(&rectangle, 3, 5);


    Ellipse ellipse;
    EllipseInitialize(&ellipse, 10, 12);


    Shape* shapes[3];
    shapes[0]=(Shape*)&circle ;
    shapes[1]=(Shape*)&rectangle ;
    shapes[2]=(Shape*)&ellipse ;


    //cout<<RectangleArea(&shapes[1])<<endl;

    double total_area=0;

    int i;
    for(i=0; i<3; i++)
    {
        double d=GetArea(shapes[i]);
        total_area+=d;
        PrintInfo(shapes[i]); // prints (cout) the radius if circle, width and height if rectangle, ... etc
    }

    cout<<total_area<<endl;

    //delete shapes;

    return 0;

}
