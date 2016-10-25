$fn = 100;

projection(cut=false) 
difference() {
    union() {
        cube([80,65,1]);
        translate([80,65/2-30/2,0]) cube([24,30,1]);
        translate([-21,65/2-22/2,0]) cube([21,22,1]);
    }
    //Mounting holes in front
    translate([80+24-6, 65/2+17.5/2]) cylinder(d=3.55);
    translate([80+24-6, 65/2-17.5/2]) cylinder(d=3.55);
    //Outer holes for PCB
    translate([5, 5]) cylinder(d=3.10);
    translate([5, 60]) cylinder(d=3.10);
    translate([5+41, 5]) cylinder(d=3.10);
    translate([5+41, 60]) cylinder(d=3.10);
    //Holes for IR sensors
    translate([68, 65/2+10/2]) cylinder(d=3.10);
    translate([68, 65/2-10/2]) cylinder(d=3.10);
}