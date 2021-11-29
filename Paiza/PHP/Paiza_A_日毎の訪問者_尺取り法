<?php
    $input = trim(fgets(STDIN));
    $input = explode(" ", $input);
    $n = $input[0];
    $k = $input[1];

    $input = trim(fgets(STDIN));
    $score = explode(" ", $input);
    $avg = array();

    $sum = 0;
    for($i = 0 ; $i < $n ; $i++)
    {
        $sum += $score[$i];
        if($i > $k-1)
        {
            $sum -= $score[$i-$k];

        }
        if($i >= $k-1) $avg[] = $sum / $k;
    }

    $max = 0;
    $day = 99999999999;
    for($i = 0 ; $i < count($avg) ; $i++)
    {
        if($max <= $avg[$i])
        {
            $max = $avg[$i];
        }
    }
    $cnt = 0;
    for($i = 0 ; $i < count($avg) ; $i++)
    {
        //echo $max."   ".$avg[$i]." \n";
        if($max == $avg[$i])
        {
            if($day > $i)
            {
                $day = $i+1;
            }
            $cnt++;
        }
    }

    echo $cnt." ".$day."\n";
?>
