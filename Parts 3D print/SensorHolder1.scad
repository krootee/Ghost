union() {
    linear_extrude(height=20) 
    {
        translate([0,0,0]) square([10,5]);
        translate([0,0,0]) rotate(90) square([15,5]);
        translate([45,15,0]) rotate(90) square([5,50]);
        translate([45,0,0]) square([5,20]);
        translate([35, 0,0]) square([10,5]);
    }
    translate([-10,-20,0]) cube([65,40,2]);
    #cylinder(size=20, height=20);
}