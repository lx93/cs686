/**
 * climate.c
 *
 * Performs analysis on climate data provided by the
 * National Oceanic and Atmospheric Administration (NOAA).
 *
 * Input:    Tab-delimited file(s) to analyze.
 * Output:   Summary information about the data.
 *
 * Compile:  run make
 *
 * Example Run:      ./climate data_tn.tdv data_wa.tdv
 *
 *
 * Opening file: data_tn.tdv
 * Opening file: data_wa.tdv
 * States found: TN WA
 * -- State: TN --
 * Number of Records: 17097
 * Average Humidity: 49.4%
 * Average Temperature: 58.3F
 * Max Temperature: 110.4F 
 * Max Temperatuer on: Mon Aug  3 11:00:00 2015
 * Min Temperature: -11.1F
 * Min Temperature on: Fri Feb 20 04:00:00 2015
 * Lightning Strikes: 781
 * Records with Snow Cover: 107
 * Average Cloud Cover: 53.0%
 * -- State: WA --
 * Number of Records: 48357
 * Average Humidity: 61.3%
 * Average Temperature: 52.9F
 * Max Temperature: 125.7F
 * Max Temperature on: Sun Jun 28 17:00:00 2015
 * Min Temperature: -18.7F 
 * Min Temperature on: Wed Dec 30 04:00:00 2015
 * Lightning Strikes: 1190
 * Records with Snow Cover: 1383
 * Average Cloud Cover: 54.5%
 *
 * TDV format:
 *
 * CA» 1428300000000»  9prcjqk3yc80»   93.0»   0.0»100.0»  0.0»95644.0»277.58716
 * CA» 1430308800000»  9prc9sgwvw80»   4.0»0.0»100.0»  0.0»99226.0»282.63037
 * CA» 1428559200000»  9prrremmdqxb»   61.0»   0.0»0.0»0.0»102112.0»   285.07513
 * CA» 1428192000000»  9prkzkcdypgz»   57.0»   0.0»100.0»  0.0»101765.0» 285.21332
 * CA» 1428170400000»  9prdd41tbzeb»   73.0»   0.0»22.0»   0.0»102074.0» 285.10425
 * CA» 1429768800000»  9pr60tz83r2p»   38.0»   0.0»0.0»0.0»101679.0»   283.9342
 * CA» 1428127200000»  9prj93myxe80»   98.0»   0.0»100.0»  0.0»102343.0» 285.75
 * CA» 1428408000000»  9pr49b49zs7z»   93.0»   0.0»100.0»  0.0»100645.0» 285.82413
 *
 * Each field is separated by a tab character \t and ends with a newline \n.
 *
 * Fields:
 *      state code (e.g., CA, TX, etc),
 *      timestamp (time of observation as a UNIX timestamp),
 *      geolocation (geohash string),
 *      humidity (0 - 100%),
 *      snow (1 = snow present, 0 = no snow),
 *      cloud cover (0 - 100%),
 *      lightning strikes (1 = lightning strike, 0 = no lightning),
 *      pressure (Pa),
 *      surface temperature (Kelvin)
 */

#include <float.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM_STATES 50

/* TODO: Add elements to the climate_info struct as necessary. */
struct climate_info {
    char code[3];
    unsigned long num_records;
    long double sum_temperature;
    long double sum_humidity;
    unsigned long lightning;
    unsigned long snow;
    unsigned long sum_cloud;
    long double max_temp;
    long double min_temp;
    long max_temp_time;
    long min_temp_time;
};
typedef struct climate_info Info;

void analyze_file(FILE *file, struct climate_info *states[], int num_states);
void print_report(struct climate_info *states[], int num_states);

int main(int argc, char *argv[]) {

    /* TODO: fix this conditional. You should be able to read multiple files. */
    /*
	if (argc != 2) {
        printf("Usage: %s tdv_file1 tdv_file2 ... tdv_fileN \n", argv[0]);
        return EXIT_FAILURE;
    }
	*/
    /* Let's create an array to store our state data in. As we know, there are
     * 50 US states. */
    Info *states[NUM_STATES] = { NULL };

    int i;
    for (i = 1; i < argc; ++i) {
        /* TODO: Open the file for reading */
        FILE *fp;
        fp = fopen(argv[i], "r");
        /* TODO: If the file doesn't exist, print an error message and move on
         * to the next file. */
        if (fp==NULL) {
            printf("Error in opening file.\n");
            fclose(fp);
            continue;
        }
        /* TODO: Analyze the file */
        else{
            analyze_file(fp, states, NUM_STATES);
        }
    }

    /* Now that we have recorded data for each file, we'll summarize them: */
    print_report(states, NUM_STATES);

    return 0;
}

void analyze_file(FILE *file, struct climate_info **states, int num_states) {
    const int line_sz = 100;
    char line[line_sz];


    while (fgets(line, line_sz, file) != NULL) {
        char* token;
        token = strtok(line,"\t\n");
        int i;
        Info* info;
        long timestamp;

        for (int ti=1;ti<10;ti++){ // using this for loop, we tokenize the line and populate the struct with the tokens
            if (ti==1) // get state
            {
                for (i = 0; i < num_states; ++i) { // look for the state specified in token in the states array
                    if (states[i] == NULL) { // if we are at the end of states[i] and have not found the state in it, we calloc a new one
                        states[i] = calloc(1,sizeof(Info));
                        strcpy(states[i]->code,token);
                        states[i]->max_temp = 0;
                        states[i]->min_temp = 999999999;
                        break;
                    }
                    else if (strcmp(states[i]->code,token)==0) break; // if we found the state code in states[i] then we found the correct i
                    else continue;
                }
                states[i]->num_records++;
                info = states[i];
            }
            if (ti==2) { // get timestamp
                timestamp = atol(token);
            }
            if (ti==4) { // get humidity
                info->sum_humidity += atoi(token);
            }
            else if (ti==5) { // get snow
                if (atoi(token) != 0) info->snow++;
            }
            else if (ti==6){ // get cloud
                info->sum_cloud+=atoi(token);
            }
            else if (ti==7) { // get lightning
                if (atoi(token) != 0) info->lightning += 1;
            }
            else if (ti==9){ // get temp
                long double temp = atof(token);
                states[i]->sum_temperature+=temp;
                if (temp>info->max_temp) {
                    info->max_temp = temp;
                    info->max_temp_time = timestamp;
                }
                if (temp<info->min_temp) {
                    info->min_temp = temp;
                    info->min_temp_time = timestamp;
                }
            }
            token = strtok(NULL,"\t\n");
        }
    }
}

/**
 * helper method that convert k to f
 * @param k temperature in k
 * @return temperature in f
 */
long double k2f (double k){
    return  k * 1.8 - 459.67;
}
/**
 * helper method that convert UNIX time to human readable time
 * @param timestamp unix time in long format
 * @return a string of human readable time
 */
char* convert_timestamp (long timestamp) {
    timestamp = timestamp / 1000;
    char * time = ctime(&timestamp);
    time[strlen(time)-1] = 0;
    return time;
}

void print_report(struct climate_info *states[], int num_states) {
    printf("\nStates found:\n");
    int i;
    for (i = 0; i < num_states; ++i) {
        if (states[i] != NULL) {
            Info *info = states[i];
            printf("%s\n", info->code);
            long num = info->num_records;
            printf("-- State: %s --\n", info->code);
            printf("Number of Records: %ld\n",num);
            printf("Average Humidity: %.1Lf%%\n",info->sum_humidity/num);
            printf("Average Temperature: %.1LfF\n",k2f(info->sum_temperature/num));
            printf("Max Temperature: %.1LfF\n",k2f(info->max_temp));
            printf("Max Temperature on: %s\n",convert_timestamp(info->max_temp_time));
            printf("Average Humidity: %.1Lf%%\n",info->sum_humidity/num);
            printf("Min Temperature: %.1LfF\n",k2f(info->min_temp));
            printf("Min Temperature on: %s\n",convert_timestamp(info->min_temp_time));
            printf("Lightning Strikes: %ld\n",info->lightning);
            printf("Records with Snow Cover: %ld\n",info->snow);
            printf("Average Cloud Cover: %ld%%\n",info->sum_cloud/num);
        }
    }
    printf("\n");

    /* TODO: Print out the summary for each state. See format above. */
}
