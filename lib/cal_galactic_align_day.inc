<?php // cal_galactic_align_day.inc


$this_date_adodb_timestamp = adodb_mktime(0, 0, 0, 2, 29, $this_date_pcs[0]);
$this_nice_date = adodb_date("D M j, Y", $this_date_adodb_timestamp);

// Insert Text from astrodreamadvisor.com (Ariel Reading)

echo "<div class=\"day_out_tm_contain\">\n";

echo "<div style=\"float: left; text-align: left; margin-top: 13px;\">";
echo "$this_nice_date is <b>0.0.Hunab ku</b>";
// Display the text reading
echo "</div>";

echo "<div style=\"float: left; text-align: left; margin-top: 13px;\">";
echo "Galactic Alignment Day is another name for LEAP DAY, which occurs on years evenly divisible by 4 but not if divisble by 100 unless evenly divisble by 400.";
echo "</div>";

echo "<div style=\"float: left; text-align: left; margin-top: 13px;\">";
echo "Galactic Alignment Day and the Day Out Of Time, the day prior to the 13-Moon New Year, which always falls on July 25, are times for great celebration!";
echo "</div>";

echo "<div style=\"float: left; text-align: left; margin-top: 13px;\">";
echo "The 13-Moon Solar Cycle begins with July 26th and ends with July 24, only 364 days.  The 365th day <b>The Day Out of Time</b>, giving the calendar 365 days per year.";
echo "</div>";

echo "</div>";

?>