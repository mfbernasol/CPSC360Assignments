<!DOCTYPE html>
<html>
<body>

<?php 
function sum( $arr, $n) 
{ 
    //initial sum 
    $sum = 0;  
  
    //loops throught array and finds sum
    for ($i = 0; $i < $n; $i++) 
    $sum += $arr[$i]; 
  
    return $sum; 
} 

//MAIN
$arr =array(2, 3, 4, 5); 
$n = sizeof($arr); 
//Prints sum output 
echo "The sum of 4 consecutive integers from 1 to 5 is ", sum($arr, $n); 
?>

</body>
</html>
