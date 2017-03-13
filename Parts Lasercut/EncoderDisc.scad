$fn = 100;

projection(cut=false)
difference() {
    
    translate([0,0,0.5]) cylinder(r = 5, h=0.1);
    cylinder(r=0.9);
    for (a = [0 : 60 : 360])
        rotate(a) translate([3.5, 0, 0]) cylinder(r=1);
}