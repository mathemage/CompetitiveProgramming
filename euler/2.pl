$a=$b=1;
do {
    $sum+=$c;
    $c=$a+$b;
    print $a,"+",$b,"=",$c,"\n";
    $a=$b+$c;
    $b=$c+$a;
} while ($c<=4000000);
print $sum
