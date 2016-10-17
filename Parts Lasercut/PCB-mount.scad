$fn = 100;

projection(cut=false) 
difference() {
    union() {
        cube([92,65,1]);
        translate([92,65/2-30/2,0]) cube([12,30,1]);
        translate([-21,65/2-21/2,0]) cube([21,21,1  ]);
    }
    //Mounting holes in front
    translate([92+12/2, 65/2+17/2]) cylinder(d=3.25);
    translate([92+12/2, 65/2-17/2]) cylinder(d=3.25);
    //Outer holes for PCB
    translate([92-6, 4]) cylinder(d=3.25);
    translate([92-6, 61]) cylinder(d=3.25);
}