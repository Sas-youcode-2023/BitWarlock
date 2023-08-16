#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

#define MAX_GRADES 20

int     main(void)
{
    float scores[MAX_GRADES];
    float totalSum = 0.0;
    int totalScores = 0;

    initscr();
    keypad(stdscr, TRUE);

    printw("Enter student scores (between 0 and 20). Entering a value outside this range will stop the program.\n");
    refresh();

    int i;
    for (i = 0; i < MAX_GRADES; i++)
    {
        printw("Enter score number %d: ", i + 1);
        refresh();
        float score;
        scanw("%f", &score);

        if (score < 0 || score > 20)
            break;

        scores[i] = score;
        totalSum += score;
        totalScores++;
    }

    if (totalScores > 0)
    {
        float average = totalSum / totalScores;
        printw("\nTotal number of scores entered: %d\n", totalScores);
        printw("Average score: %.2f\n\n", average);

        int aboveAverageCount = 0;
        for (int j = 0; j < totalScores; j++)
        {
            printw("Score number %d: %.2f ", j + 1, scores[j]);
            if (scores[j] > average) {
                printw("above average\n");
                aboveAverageCount++;
            }
            else if (scores[j] < average)
                printw("below average\n");
            else
                printw("equal to average\n");
            refresh();
        }

        printw("\nNumber of scores above average: %d\n", aboveAverageCount);

        float highestScore = scores[0];
        int highestPosition = 0;
        float lowestScore = scores[0];
        int lowestPosition = 0;

        for (int j = 1; j < totalScores; j++)
        {
            if (scores[j] > highestScore)
            {
                highestScore = scores[j];
                highestPosition = j;
            }
            if (scores[j] < lowestScore)
            {
                lowestScore = scores[j];
                lowestPosition = j;
            }
        }

        printw("Highest score: %.2f at position %d\n", highestScore, highestPosition + 1);
        printw("Lowest score: %.2f at position %d\n", lowestScore, lowestPosition + 1);
    }
    else
        printw("No scores entered.\n");

    refresh();
    getch();
    endwin();

    return 0;
}
