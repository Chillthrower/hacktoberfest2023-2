
// Done by using the-zorro-project https://zorro-project.com/
function run()
{
	StartDate = 20220101;
	EndDate = 20230101;
	LookBack = 300;
	asset("EUR/USD");
	set(LOGFILE, PLOTNOW);
	vars Prices = series(priceClose());
	vars slowma = series(MovingAverage(Prices, 200, MAType_SMA));
	vars fastma = series(MovingAverage(Prices, 50, MAType_SMA));
	vars TrendIndicator = series(LowPass(Prices, 300));
	vars MMI_Indicator_Raw = series(MMI(Prices, 300));
	vars MMI_Indicator_Smooth = series(LowPass(MMI_Indicator_Raw, 300));
	
	if(valley(TrendIndicator))
	{
		enterLong();
	}
	else if(peak(TrendIndicator))
	{
		enterShort();
	}
	
	if(crossOver(fastma, slowma))
	{
		enterLong();
	}
	else if(crossUnder(fastma, slowma))
	{
		enterShort();
	}
	
	PlotWidth = 1200;
	PlotScale = 10;
	
	plot("Fast MA", fastma, LINE, RED);
	plot("slowma MA", slowma, LINE, BLUE);
	plot("Low pass", TrendIndicator, LINE + NEW, ORANGE);
	plot("MMI Raw data", MMI_Indicator_Raw, LINE + NEW, GREY);
	plot("MMI overall trend", MMI_Indicator_Smooth, LINE, GREEN);
	

}
