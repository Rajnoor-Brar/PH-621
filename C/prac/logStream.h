#pragma once
#include<stdio.h>
#include<stdlib.h>

static FILE *warningFile = NULL;

static FILE *noticeFile = NULL;

static FILE *warningLog(void)
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

static FILE *noticeLog(void)
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
    fprintf(stderr, "(\033[1m%s\033[22m : %d) Error : " fmt "\n", \
            __FILE__, __LINE__, ##__VA_ARGS__)

#define WARNING(fmt, ...) \
    fprintf(warningLog(), "Warning (%s : %d): " fmt "\n", \
            __FILE__, __LINE__, ##__VA_ARGS__)

#define NOTICE(fmt, ...) \
    fprintf(noticeLog(), "Notice (%s : %d): " fmt "\n", \
            __FILE__, __LINE__, ##__VA_ARGS__)


// input arguments ( TERM VALUE , PRECISION THRESHOLD, STEP NUMBER )

#define PRECISION_REACHED_BREAK \
    "Term (%g) is below precision threshold (%g). Breaking at step %d. \n"

#define PRECISION_REACHED_NOBREAK \
    "Term (%g) reached precision threshold (%g) at step %d. Continuing forth.\n"


// input arguments ( TERM VALUE , PRECISION THRESHOLD)

#define PRECISION_REACHED \
    "Term (%g) has dropped below precision threshold (%g). \n"

#define PRECISION_NOT_REACHED \
    "Term (%g) has NOT dropped below precision threshold (%g). Answer may not be accurate.\n"
    

#define OUT_OF_DOMAIN \
    "Value is out of range of acceptable range\n"

#define OUT_OF_THIS_DOMAIN \
    "Value is out of domain. Acceptable domain is [%s , %s]\n"

#define DIVISION_BY_ZERO \
    "Division by zero is undefined\n"

#define NEGATIVE_INPUT \
    "Negative input is not acceptable\n"

#define ZERO_INPUT \
    "Zero input is not acceptable\n"

#define POSITIVE_DOMAIN \
    "Acceptable domain is strictly positive values\n"

#define INVALID_INPUT \
    "Input is invalid\n"

