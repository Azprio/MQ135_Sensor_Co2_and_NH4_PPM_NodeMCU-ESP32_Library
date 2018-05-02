
#define MQ135_PULLDOWNRES 10000         
#define default_ppm_CO2 408
#define default_ppm_NH4 5

#include <math.h>

int i = 0;
double rs;
double ro_co2;
double ro_nh4;
double rs_ro_ratio_co2;
double rs_ro_ratio_nh4;
int co2_ppm;
float nh4_ppm;
int adcread;
void MQ135_init(int sample_rate,int Analog_val) {
  adcread = Analog_val;
  	if(sample_rate == 4096){
		adcread = adcread/4;
		}
  rs = (double)((double)(1024*(long)MQ135_PULLDOWNRES)/adcread-(long)MQ135_PULLDOWNRES);
  ro_co2 = (double)rs/(5.1396*pow(default_ppm_CO2,(-.347)));
  ro_nh4 = (float)rs/(6.43*pow(default_ppm_NH4,(-.403)));
}

int read_CO2(int sample_rate,int Analog_val) {
  
  
  adcread = Analog_val;
	if(sample_rate == 4096){
		adcread = adcread/4;
		}
  rs = (double)((double)(1024*(long)MQ135_PULLDOWNRES)/adcread-(long)MQ135_PULLDOWNRES);
  rs_ro_ratio_co2 = (double)rs/(double)ro_co2;
	co2_ppm = exp((log(rs_ro_ratio_co2/5.1396)/(-.347)));
 
  return co2_ppm;
}

float read_NH4(int sample_rate,int Analog_val) {
  
  
  adcread = Analog_val;
	if(sample_rate == 4096){
		adcread = adcread/4;
		}
  rs = (float)((float)(1024*(long)MQ135_PULLDOWNRES)/adcread-(long)MQ135_PULLDOWNRES);
  rs_ro_ratio_nh4 = (float)rs/(float)ro_nh4;
	nh4_ppm = exp((log(rs_ro_ratio_nh4/6.43)/(-.403)));
	
	return nh4_ppm;
}