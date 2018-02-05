/*
 * PCB outline for Ghost ESP32 (rev 4)
 * Frode Lillerud, 11.aug 2017
 */

$fn=100;

length = 63;
width = 43;
corner_length = 10;
corner_width = 8;

module corner() {
    union ()
    {
        cube([corner_length, corner_width, 1], center=true);
        translate([corner_width/2, 0, 0]) cylinder(d=corner_width, center=true);
    }
}

projection(cut=false)
union() {    
    cube([length,width,1], center=true);
    translate([length/2,width/2,0]) rotate(45) corner();
    translate([length/2,-width/2,0]) rotate(-45) corner();
    translate([-length/2,width/2,0]) rotate(135) corner();
    translate([-length/2,-width/2,0]) rotate(-135) corner();
}