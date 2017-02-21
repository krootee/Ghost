$fn=100;

module sensor()
{
    width = 8;
    translate([0,-2.5,-5])
    union() {
        color("black") cube([5.5,5,10]);
        translate([5,-1.5,-3]) color("green") cube([1,width,19]);
    }
}

module side()
{
    translate([30,45/2,0]) 
    {
        difference()
        {
            cube([75,10,1], center=true);
            #rotate(-45) sensor();
            #rotate(-135) sensor();
        }
    }
}

module curve()
{
difference()
{
    circle(30);
    circle(20);
    for (a = [-60 : 26 : 60])
        rotate(a) translate([19, 0, 0]) sensor();
}
}

difference() {

    union() {
        translate([-10,0,0]) curve();
        
        //side();
        //mirror([0,1,0]) side();
        //translate([30,-17+2.5,0]) cube([60,5,1], center=true);
    }
    translate([-25,0,0]) cube([50,100,3], center=true);
    sensor();
}