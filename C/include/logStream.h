#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdarg.h>
// #pragma GCC diagnostic ignored "-Wunused-function"
// #pragma clang diagnostic ignored "-Wunused-function"

static FILE *logStream = NULL;

static inline void logInitialise(char *stream){
    char name[256];
    if (logStream){
        fclose(logStream);
        logStream = NULL;
    }
    snprintf(name, sizeof name, "log_st_%s.txt", stream);
    logStream = fopen(name, "w");
    if (!logStream) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }
}

static inline void logClose(void){
    if (logStream) {
        fclose(logStream);
        logStream = NULL;
    }
}

static inline void streamLog(const char *fmt, ...){
    if (!logStream) {
        fprintf(stderr, "Log stream not initialized. Call logInitialise() first.\n");
        return;
    }
    va_list args;
    va_start(args, fmt);
    vfprintf(logStream, fmt, args);
    va_end(args);
}



// ----------------------Error Management ---------------

static FILE *warningFile = NULL;

static FILE *noticeFile = NULL;

static struct tm* timeFormat = NULL;

static time_t timeValue;

static char *currentTime(void){
    time(&timeValue);
    timeFormat = localtime(&timeValue);
    char *timeString = asctime(timeFormat);
    timeString[24] = '\0';
    return timeString;
}

static inline FILE *warningLog(void)
{
    if (!warningFile) {
        warningFile = fopen("log_Warnings.txt", "a+");
        if (!warningFile) {
            perror("fopen");
            exit(EXIT_FAILURE);
        }
    }
    return warningFile;
}

static inline FILE *noticeLog(void)
{
    if (!noticeFile) {
        noticeFile = fopen("log_Notices.txt", "a+");
        if (!noticeFile) {
            perror("fopen");
            exit(EXIT_FAILURE);
        }
    }
    return noticeFile;
}

#define ERROR(fmt, ...) \
    fprintf(stderr, "(\033[1m%s\033[22m : %d) Error : " fmt "\n\n", \
            __FILE__, __LINE__, ##__VA_ARGS__)

#define WARNING(fmt, ...) \
    fprintf(warningLog(), "Warning [%s]\n\t\tL%03d  |  %s : \n\t" fmt "\n\n", \
            currentTime(), __LINE__, __FILE__, ##__VA_ARGS__)

#define NOTICE(fmt, ...) \
    fprintf(noticeLog(), "Notice [%s]\n\t\tL%03d  |  %s  : \n\t" fmt "\n\n", \
            currentTime(), __LINE__, __FILE__, ##__VA_ARGS__)

// input arguments ( TERM VALUE , PRECISION THRESHOLD, STEP NUMBER )

#define PRECISION_REACHED_BREAK \
    "Term (%g) is below precision threshold (%g). Breaking at step %d."

#define PRECISION_REACHED_NOBREAK \
    "Term (%g) reached precision threshold (%g) at step %d. Continuing forth."


// input arguments ( TERM VALUE , PRECISION THRESHOLD)

#define PRECISION_REACHED \
    "Term (%g) has dropped below precision threshold (%g)."

#define PRECISION_NOT_REACHED \
    "Term (%g) has NOT dropped below precision threshold (%g). Answer may not be accurate."
    

#define OUT_OF_DOMAIN \
    "Value is out of range of acceptable range"

#define OUT_OF_THIS_DOMAIN \
    "Value is out of domain. Acceptable domain is [%s , %s]"

#define DIVISION_BY_ZERO \
    "Division by zero is undefined"

#define NEGATIVE_INPUT \
    "Negative input is not acceptable"

#define ZERO_INPUT \
    "Zero input is not acceptable"

#define POSITIVE_DOMAIN \
    "Acceptable domain is strictly positive values"

#define INVALID_INPUT \
    "Input is invalid"

#define UNSTOPPING_LOOP \
    "Loop has run too many iterations. Force stopping for safety."
    
#define INFINITE_LOOP \
    "Invalid Break Condition. Force stopping for safety."

#define DISTANT_CONVERGENCE \
    "Loop has run iteration limit of %d without convergence. Force stopping for safety."