$n = trim(fgets(STDIN));

    $nums = array();
    for($i = 0 ; $i < 7 ; $i++) $nums[] = 0;

    for($i = 0 ; $i < $n ; $i++)
    {
        $a = trim(fgets(STDIN)) % 7;
        $nums[$a]++;
    }

    $ans = 0;
    for($x = 0 ; $x < 7 ; $x++)
    {
        for($y = $x ; $y < 7 ; $y++)
        {
            for($z = $y ; $z < 7 ; $z++)
            {
                if(($x+$y+$z) % 7 == 0)
                {
                    $xx = $nums[$x];
                    $yy = $nums[$y];
                    $zz = $nums[$z];
                    if($x==$y) $yy--;
                    if($y==$z) $zz--;
                    if($x==$z) $zz--;
                    $pat = $xx * $yy * $zz;
                    if($x==0 && $y==0 && $z==0)
                    {
                        $pat /= 6;
                    }
                    else if($x == $y || $y == $z || $z == $x)
                    {
                        $pat /= 2;
                    }
                    $ans += $pat;
                }
            }
        }
    }

    echo $ans;
