$fn = 100;

projection(cut=false)
difference() {
    
    translate([0,0,0.5]) cylinder(r = 8.5, h=0.1);
    cylinder(r=0.9);
    for (a = [0 : 30 : 360])
        rotate(a) translate([7, 0, 1]) cube([3,1.2,1], center=true); //cylinder(r=0.8);
}