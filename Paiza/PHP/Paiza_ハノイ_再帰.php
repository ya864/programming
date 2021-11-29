<?php
    
    $_from = array();
    $_to = array();

    $input = trim(fgets(STDIN));
    $input = explode(" ", $input);
    $n = $input[0];
    $t = $input[1];
    
    hanoi($n, 0, 2, 1);
    
    $sticks = array();
    for($i = 0 ; $i < 3 ; $i++)
    {
        $sticks[] = array();
    }
    for($i = 0; $i < $n; $i++)
    {
      $sticks[0][] = $n-$i;
    }
  
    for($i = 0 ; $i < $t ; $i++)
    {
        $a = array_shift($_from);
        $b = array_shift($_to);
        $c = array_pop($sticks[$a]);
        $sticks[$b][] = $c;
    }
  
    for($i = 0; $i < 3 ; $i++)
    {
        if(count($sticks[$i])==0){
            echo "-";
        }
        else
        {
            $ans = implode(" ", $sticks[$i]);
            echo $ans;
        }
        echo "\n";
    }
    
    function hanoi($n, $from, $to, $work)
    {
        global $_from;
        global $_to;
        
        if($n > 0)
        {
            hanoi($n-1, $from, $work, $to);
            $_from[] = $from;
            $_to[] = $to;
            hanoi($n-1, $work, $to, $from);
        }
    }
    
?>
