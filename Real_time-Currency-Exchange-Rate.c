#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

// Constants
#define MAX_CURRENCY_NAME 4
#define RATE_FLUCTUATION_THRESHOLD 0.05 // 5% fluctuation threshold

// Currency exchange rate structure
typedef struct {
    double* rate;           // Pointer to the exchange rate value
    char currency[MAX_CURRENCY_NAME]; // Currency code (e.g., "EUR" or "GBP")
} ExchangeRate;

// Mutex for rate updates
pthread_mutex_t rateMutex = PTHREAD_MUTEX_INITIALIZER;

// Function to update exchange rates (simulated)
void* updateRates(void* arg) {
    ExchangeRate* exchangeRate = (ExchangeRate*)arg;
    while (1) {
        // Simulated rate fluctuation
        double fluctuation = ((double)rand() / RAND_MAX - 0.5) * 2 * RATE_FLUCTUATION_THRESHOLD;
        pthread_mutex_lock(&rateMutex);
        *(exchangeRate->rate) += fluctuation;
        pthread_mutex_unlock(&rateMutex);
        sleep(1); // Update rates every second (simulated)
    }
    return NULL;
}

// Function to convert USD to another currency
double convertToCurrency(double amount, const double* rate) {
    return amount * (*rate);
}

// Function to notify the user of rate fluctuations
void notifyRateFluctuation(const ExchangeRate* exchangeRate) {
    double rate = *(exchangeRate->rate);
    if (rate >= 1 + RATE_FLUCTUATION_THRESHOLD) {
        printf("ALERT: The %s rate has increased significantly! Current rate: %.2lf\n", exchangeRate->currency, rate);
    } else if (rate <= 1 - RATE_FLUCTUATION_THRESHOLD) {
        printf("ALERT: The %s rate has decreased significantly! Current rate: %.2lf\n", exchangeRate->currency, rate);
    }
}

int main() {
    // Simulated initial exchange rates (replace with real data source)
    double usd_to_eur = 0.85;
    double usd_to_gbp = 0.75;
    double usd_to_bdt = 84.50;

    // Exchange rate structures
    ExchangeRate eurRate = {&usd_to_eur, "EUR"};
    ExchangeRate gbpRate = {&usd_to_gbp, "GBP"};
    ExchangeRate bdtRate = {&usd_to_bdt, "BDT"};

    // Threads for rate updates
    pthread_t eurThread, gbpThread, bdtThread;
    pthread_create(&eurThread, NULL, updateRates, &eurRate);
    pthread_create(&gbpThread, NULL, updateRates, &gbpRate);
    pthread_create(&bdtThread, NULL, updateRates, &bdtRate);

    // Simulated currency conversion and notification logic
    while (1) {
        double amount;
        printf("Enter an amount in USD: ");
        scanf("%lf", &amount);

        // Convert to other currencies
        double eurAmount = convertToCurrency(amount, eurRate.rate);
        double gbpAmount = convertToCurrency(amount, gbpRate.rate);
        double bdtAmount = convertToCurrency(amount, bdtRate.rate);

        printf("Converted Amount (EUR): %.2lf\n", eurAmount);
        printf("Converted Amount (GBP): %.2lf\n", gbpAmount);
        printf("Converted Amount (BDT): %.2lf\n", bdtAmount);

        // Check for rate fluctuations and notify the user
        notifyRateFluctuation(&eurRate);
        notifyRateFluctuation(&gbpRate);
        notifyRateFluctuation(&bdtRate);

        sleep(2); // Wait for user input (simulated)
    }

    // Cleanup and exit
    pthread_cancel(eurThread);
    pthread_cancel(gbpThread);
    pthread_cancel(bdtThread);

    return 0;
}
