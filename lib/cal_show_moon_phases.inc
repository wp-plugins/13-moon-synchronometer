<?php // cal_show_moon_phases.inc

// Get moon ILLUMINATION for this day 12:01pm using Moon class, store in $moon_status
$tmc_cal_anyting = list($MoonPhase, $MoonAge, $MoonDist, $MoonAng, $SunDist, $SunAng, $mpfrac) = Moon::phase($this_date_pcs[0], $this_date_pcs[1], $this_date_pcs[2], 0, 0, 0);

$moon_status = number_format($MoonPhase*100, 1, '.', '');

// Get moon phase for this day using func: moon_phase.
$moon_name = moon_phase($this_date_pcs[0], $this_date_pcs[1], $this_date_pcs[2]);

$moon_img = "";

if ($moon_name === "New Moon"){		$moon_img = "<img src=\"$moons_img_dir/moon_new.gif\" width=55 height=55 alt=\"$moon_name\">";}
if ($moon_name === "Waxing Crescent"){	$moon_img	= "<img src=\"$moons_img_dir/moon_waxc.gif\" width=55 height=55 alt=\"$moon_name\">";}
if ($moon_name === "First Quarter"){	$moon_img	= "<img src=\"$moons_img_dir/moon_fq.gif\" width=55 height=55 alt=\"$moon_name\">";}
if ($moon_name === "Waxing Gibbous"){	$moon_img	= "<img src=\"$moons_img_dir/moon_waxg.gif\" width=55 height=55 alt=\"$moon_name\">";}
if ($moon_name === "Full Moon"){		$moon_img	= "<img src=\"$moons_img_dir/moon_full.gif\" width=55 height=55 alt=\"$moon_name\">";}
if ($moon_name === "Waning Gibbous"){	$moon_img	= "<img src=\"$moons_img_dir/moon_wang.gif\" width=55 height=55 alt=\"$moon_name\">";}
if ($moon_name === "Last Quarter"){	$moon_img	= "<img src=\"$moons_img_dir/moon_lq.gif\" width=55 height=55 alt=\"$moon_name\">";}
if ($moon_name === "Waning Crescent"){	$moon_img	= "<img src=\"$moons_img_dir/moon_wanc.gif\" width=55 height=55 alt=\"$moon_name\">";}

// show moon img - Name of Lunar Phase and percent
if ($moon_img !== ""){

// Display ON or OFF


	echo "<div class=\"moon_group\" id=\"moon_group_id\">";

	echo "<div class=\"moon_img\">";
	echo "$moon_img";
	echo "</div>\n";

	echo "<div class=\"moon_info\">";
	echo "$moon_status"."%"."<br>$moon_name";
	echo "</div>\n";

	echo "</div>\n";
}

?>