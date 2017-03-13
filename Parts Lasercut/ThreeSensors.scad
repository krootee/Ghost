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
    cube([45, 10, 3], center=true);
    
    translate([10,-6.5,0]) rotate(60) sensor();
    mirror() translate([10,-6.5,0]) rotate(60) sensor();
    
    rotate(90) translate([-7,0,0]) sensor();
    
    translate([19,1,-2]) cylinder(r=1.52, h=10);
    mirror() translate([19,1,-2]) cylinder(r=1.52, h=10);
}