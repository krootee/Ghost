$fn=100;

module sensor()
{
    width = 8;
    scaleFactor = 1.21;
    
    scale(scaleFactor)
    translate([0,-2.5,-5])
    union() {
        cube([5.5,5,10]);
        translate([5,-1.5,-3]) cube([1,width,19]);
    }
}


projection(cut=false)
difference() 
{
    cube([35, 10, 3], center=true);
    translate([5,-6.5,0]) rotate(60) sensor();
    mirror() translate([5,-6.5,0]) rotate(60) sensor();
    //translate([-5, -6.5, 0]) rotate(120) sensor();
    
    translate([14,1,-2]) cylinder(r=1.52, h=10);
    mirror() translate([14,1,-2]) cylinder(r=1.51, h=10);
}