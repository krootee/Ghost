$fn=100;
radius = 4;
width = 80;
height = 49;
hole = 3.2;

projection(cut=false) 
difference() {
    translate([radius, radius, 0]) minkowski()
    {
        cube([width-radius,height-radius,1]);
        cylinder(r=radius,h=1);
    }
    translate([radius,radius,0]) cylinder(10, r=hole/2);
    translate([width,radius,0]) cylinder(10, r=hole/2);
    translate([radius,height,0]) cylinder(10, r=hole/2);
    translate([width,height,0]) cylinder(10, r=hole/2);
}