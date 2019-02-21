#include "Window.h"
#include "Simple_window.h"
#include "Graph.h"
#include <stdexcept>
#include <chrono>
#include <thread>
#include <math.h>

using namespace Graph_lib;

struct Throw_window : Graph_lib::Window {
    Throw_window(Point xy, int w, int h, const string& title );
    Axis xa;int x, y;double t; double th;double multi;bool param;
    Axis ya;
    Text tx;
    Text ty;
    Text he;
    Image ii;
    double v;
    double deg;
    int cnt;
    
	private:
    Button startbtn;        
    In_box speed;
    In_box angle;

    static void cb_start(Address, Address);
    void start();
    void throw_it (int, double );
    static void cb(void*);
};

Throw_window::Throw_window(Point xy, int w, int h, const string& title)
    :Window(xy,w,h,title),
    startbtn(Point(x_max()-230,10), 70, 20, "Throw!", cb_start),
    speed(Point(x_max()-310,10), 70, 20, "Speed (m/s):"),
    angle(Point(x_max()-310,35), 70, 20, "Angle (degrees):"),
    xa(Axis::x, Point{20,500}, 400, 10, "Distance"),
    ya(Axis::y, Point{20,500}, 400, 10, "Maximum height: "),
    tx(Point{250,320},""),
    ty(Point{50,320},""),
    he(Point{50,320},""),
    ii(Point{17,473},"Rock.png")
  
{
    attach(startbtn);
    attach(speed);
    attach(angle);
    int x = 0, y = 0;
	double t = 0;
	double th = 0;
	double multi = 1;
	bool param = false;
	v = 0.0;
	cnt = 0;
	deg = 0.0;
	ya.set_color(Color::black);
	xa.set_color(Color::black);
	tx.set_color(Color::black);
	ty.set_color(Color::black);
	he.set_color(Color::black);
	he.set_position(150, 90);
	ty.set_position(27, 127);
	attach(xa);
	attach(ya);
	attach(tx);
	attach(ty);
	attach(he);
	attach(ii);
}

void Throw_window::cb_start(Address, Address pw)  
{   
    reference_to<Throw_window>(pw).start();
}
void Throw_window::throw_it (int angle, double v){
	long double PI = acos(-1);
	ostringstream stream;
	ostringstream stream2;
	ostringstream stream3;
	double vspeed = sin((angle*PI)/180)*v;
	double hspeed = cos((angle*PI)/180)*v;
	th = vspeed/9.8;
	double ymax = vspeed*th - 0.5*9.8*th*th;
	double xmax = hspeed * th*2;
	multi = 360/xmax;
	if(ymax*multi>360)multi = 360/ymax;
	
	y = (vspeed*t - 0.5*9.8*t*t)*multi;
	x = hspeed*t*multi;
	
	stream<<setprecision(2)<<fixed<<x/multi<<"m";
	stream2<<setprecision(2)<<fixed<<ymax<<"m, "<<"time: "<<t<<"s";
	stream3<<setprecision(2)<<fixed<<y/multi<<"m";
	tx.set_label(stream.str());
	tx.set_position(xmax*multi, 540);
	he.set_label(stream2.str());
	if(xmax>=20000) tx.set_label("Into the orbit");
	ty.set_label(stream3.str());
}

void Throw_window::cb(void* obj){
	Throw_window *p = reinterpret_cast<Throw_window*>(obj);
	p->throw_it(p->deg, p->v);
    
    if(p->th*2.0>p->t + 0.1){
    	p->t +=0.03;
    	p->ii.set_position(p->x+17,-p->y+473);
    	Fl::redraw();
    	Fl::repeat_timeout(0.03, cb, p);
    } else {
    	p->cnt++;
    	p->t = p->th*2; 
     	p->ii.set_position(p->x+17,-p->y+473);
    	Fl::redraw();
    	if(p->cnt!=2)
    		Fl::repeat_timeout(0.03, cb, p);
    	else {
    		p->t = 0;
    		p->cnt = 0;
    	}	
    	
    }
}
void Throw_window::start()
{	
	Fl::remove_timeout(cb);
	v = 0;
	deg = 0;
	v = speed.get_double();
	deg = angle.get_double();
	if(deg>90) deg = 90;
	if(deg<0) deg = 0;
	if(v<=0) v = 0;
	t = 0;
	th = 0;
	cnt = 0;
	cb(this);
    //Fl::add_timeout(0.5, cb, this);
}

int main(){
try {
    Throw_window win(Point(100,100),600,600,"ThrowMe!");
    return gui_main();
}
catch(exception& e) {
    cerr << "exception: " << e.what() << '\n';
    return 1;
}
catch (...) {
    cerr << "Some exception\n";
    return 2;
}
}
