// The very first hackathon.
// Cat Damon, our resident cat, provides some 
// much needed advice to people in quarantine.
// The program will only end once the user is happy.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_USERNAME_LENGTH 100
#define MAX_LINE_LENGTH 900

#define SAD 2
#define BORED 3
#define STRESSED 4
#define LONELY 5
#define HAPPY 6
#define NONE 7

// Peter Function Prototypes.
void printCatIcon(void);
void printTiredCat(void);
void printSadCat(void);
int wordRecogCounter(
    char baseString[MAX_LINE_LENGTH], 
    char inputWord[MAX_LINE_LENGTH]
);
void upperToLowercase(char stringInput[MAX_LINE_LENGTH]);
int emotionDetector(char emotionString[MAX_LINE_LENGTH]);
void sad(void);

// Alex Function Prototypes.
void getUsername(char username[MAX_USERNAME_LENGTH]);
void printName(char username[MAX_USERNAME_LENGTH]);
void lonely();
void cocktailRecipes();
int maxFeeling(
    int feeling1, int feeling2, int feeling3, 
    int feeling4, int feeling5
);
void printLonelyCat();


// Joseph Function Prototypes.
void howAreYou(char howAreYouInput[MAX_LINE_LENGTH]);
void bored(void);

// Riley Function Prototypes.
void stressed();
int wordRecogCounter(
    char baseString[MAX_LINE_LENGTH], 
    char inputWord[MAX_LINE_LENGTH]
);
int check_yes(void);


int main(void) {
    
    printCatIcon();
    
    char username[MAX_USERNAME_LENGTH] = {0};
    getUsername(username);
    
    int overallEmotion = 0;
    while (overallEmotion != HAPPY) {
    
      overallEmotion = 0;
      
      char initialInput[MAX_LINE_LENGTH] = {0}; 
      howAreYou(initialInput);
      
      overallEmotion = emotionDetector(initialInput);
      
      if (overallEmotion == SAD) {
          sad();
          getchar();
          printf("\n");
      } else if (overallEmotion == BORED) {
          bored();
          getchar();
          printf("\n");
      } else if (overallEmotion == STRESSED) {
          stressed();
          printf("\n");
      } else if (overallEmotion == LONELY) {
          lonely();
          getchar();
          printf("\n");
      } else if (overallEmotion != HAPPY) {
        printf("Please use more emotive language lol\n");
        printf("\n");
      } else if (overallEmotion == HAPPY) {
        printf("\nGlad to hear it, ");
        printName(username);
        printf(". Stay Safe!\n");
      }
      
    }
    return 0;
}

// ALL FUNCTIONS BEGIN HERE

// Prints the greeting cat character.
void printCatIcon(void) {
    
    printf("                          /)\n");
    printf("                 /\\___/\\ ((\n");
    printf("                 \\`@_@'/  ))\n");
    printf("                 {_:Y:.}_//\n");
    printf("-----------------{_}^-'{_}------------------\n"); 
}

void getUsername(char username[MAX_USERNAME_LENGTH]) {
  printf("Hey! My name's Cat Damon. What’s your name?\n");
  fgets(username, MAX_USERNAME_LENGTH, stdin);
  
  printf("\nNice to meet you ");
  printName(username);
  printf("!\n");
}

// A function to print the username, without the \n at the end.
void printName(char username[MAX_USERNAME_LENGTH]){
  int nameLength = strlen(username);
  int i = 0;
  while (i < nameLength) {
    if (username[i] != '\n') {
        printf("%c", username[i]);
    }
    i++;
  }

}

// Asks user how they're feeling today and stores in array.
void howAreYou(char howAreYouInput[MAX_LINE_LENGTH]) { 
    printf("How are you feeling?\n");
    fgets(howAreYouInput, MAX_LINE_LENGTH, stdin);
    
}

// Prints a tired cat character.
void printTiredCat(void) {
    
    printf("      |\\      _,,,---,,_\n");
    printf("ZZZzz /,`.-'`'    -.  ;-;;,_\n");
    printf("     |,4-  ) )-,_. ,\\ (  `'-'\n");
    printf("    '---''(_/--'  `-'\\_)\n");
}

// Prints a sad cat character.
void printSadCat(void) {
    printf("      _____\n");
    printf("     / >   >\n");
    printf("    |   _  _|\n");
    printf("     '=___x /\n");
    printf("     /     |\n");
    printf("    /  \\   )\n");
    printf("    |  | | | \n");
    printf("  __|  | | |\n");
    printf(" / _   | | |    \n");
    printf("| (_\\_\\__)__)\n");
    printf("\\__ )\n");
}


// First converts the base string 
// Compares two strings and returns the number of occurrences
// of the second input in the first.
int wordRecogCounter(
    char baseString[MAX_LINE_LENGTH], 
    char inputWord[MAX_LINE_LENGTH]
) {
    upperToLowercase(baseString);
    
    int wordFrequency = 0;
    char *ptr = strstr(baseString, inputWord);
    
    if (ptr != NULL) /* Word found */
    {
        wordFrequency++;  
    } 
    ptr = strstr(baseString, inputWord);

	return wordFrequency; 
}

void upperToLowercase(char stringInput[MAX_LINE_LENGTH]) {
    int i = 0;
    int stringLength = strlen(stringInput);
    while(i < stringLength) {
        // If the element is an uppercase letter, convert it to lowercase
        if(
            'A' <= stringInput[i] && stringInput[i] <= 'Z'
        ) {
            stringInput[i] = stringInput[i] + 32;
        }
        i++;
    } 
}

// Scans through an input string and calculates the number of
// sad, bored, stressed, lonely and happy words in a string.
int emotionDetector(char emotionString[MAX_LINE_LENGTH]) {
    
    int sadCounter = 0;
    
    sadCounter += wordRecogCounter(emotionString, "sad");
    sadCounter += wordRecogCounter(emotionString, "upset");
    sadCounter += wordRecogCounter(emotionString, "depressed");
    sadCounter += wordRecogCounter(emotionString, "bad");
    sadCounter += wordRecogCounter(emotionString, "annoyed");
    sadCounter += wordRecogCounter(emotionString, "annoy");
    sadCounter += wordRecogCounter(emotionString, "cranky");
    sadCounter += wordRecogCounter(emotionString, "awful");
    sadCounter += wordRecogCounter(emotionString, "shit");
    sadCounter += wordRecogCounter(emotionString, "terrible");
    sadCounter += wordRecogCounter(emotionString, "not good");
    sadCounter += wordRecogCounter(emotionString, "not happy");
    sadCounter += wordRecogCounter(emotionString, "crap");
    
    int boredCounter = 0;
    
    boredCounter += wordRecogCounter(emotionString, "bored");
    boredCounter += wordRecogCounter(emotionString, "nothing to do");
    boredCounter += wordRecogCounter(emotionString, "unexciting"); 
    boredCounter += wordRecogCounter(emotionString, "dull");
    boredCounter += wordRecogCounter(emotionString, "I'm over it");
    boredCounter += wordRecogCounter(emotionString, "blah");
    boredCounter += wordRecogCounter(emotionString, "whatever");
    
    int stressedCounter = 0;
    
    stressedCounter += wordRecogCounter(emotionString, "tired");
    stressedCounter += wordRecogCounter(emotionString, "exhausted");
    stressedCounter += wordRecogCounter(emotionString, "sleepy");
    stressedCounter += wordRecogCounter(emotionString, "slept badly");
    stressedCounter += wordRecogCounter(emotionString, "couldn't sleep");
    stressedCounter += wordRecogCounter(emotionString, "stressed");
    stressedCounter += wordRecogCounter(emotionString, "angry");
    stressedCounter += wordRecogCounter(emotionString, "burnt out");
    stressedCounter += wordRecogCounter(emotionString, "busy");
    
    int lonelyCounter = 0;
    
    lonelyCounter += wordRecogCounter(emotionString, "lonely");
    lonelyCounter += wordRecogCounter(emotionString, "alone");
    lonelyCounter += wordRecogCounter(emotionString, "by myself");
    lonelyCounter += wordRecogCounter(emotionString, "on my own");
    lonelyCounter += wordRecogCounter(emotionString, "isolated");
    lonelyCounter += wordRecogCounter(emotionString, "quarantine");
    lonelyCounter += wordRecogCounter(emotionString, "isolation");
    lonelyCounter += wordRecogCounter(emotionString, "friendless");
    lonelyCounter += wordRecogCounter(emotionString, "secluded");
    lonelyCounter += wordRecogCounter(emotionString, "no friends");
    lonelyCounter += wordRecogCounter(emotionString, "horny");
    lonelyCounter += wordRecogCounter(emotionString, "randy");

    int happyCounter = 0;

    happyCounter += wordRecogCounter(emotionString, "happy");
    happyCounter += wordRecogCounter(emotionString, "great");
    happyCounter += wordRecogCounter(emotionString, "good");
    happyCounter += wordRecogCounter(emotionString, "fun");
    happyCounter += wordRecogCounter(emotionString, "not bad");
    happyCounter += wordRecogCounter(emotionString, "epic");
    happyCounter += wordRecogCounter(emotionString, "awesome");
    happyCounter += wordRecogCounter(emotionString, "top notch");
    happyCounter += wordRecogCounter(emotionString, "fantastic");
    happyCounter += wordRecogCounter(emotionString, "amazing");
    happyCounter += wordRecogCounter(emotionString, "glad");
    happyCounter += wordRecogCounter(emotionString, "lol");
    happyCounter += wordRecogCounter(emotionString, "haha");
    happyCounter += wordRecogCounter(emotionString, "better");
    happyCounter += wordRecogCounter(emotionString, "brilliant");
  
    int mostCommonFeeling = maxFeeling(
        sadCounter, boredCounter, stressedCounter, 
        lonelyCounter, happyCounter
    );
    
    if (mostCommonFeeling == sadCounter) {
        mostCommonFeeling = SAD;
    } else if (mostCommonFeeling == boredCounter) {
        mostCommonFeeling = BORED;
    } else if (mostCommonFeeling == stressedCounter) {
        mostCommonFeeling = STRESSED;
    } else if (mostCommonFeeling == happyCounter){
        mostCommonFeeling = HAPPY;
    } else if (mostCommonFeeling == lonelyCounter) {
        mostCommonFeeling = LONELY;
    }
    
    return mostCommonFeeling;
    
}

int maxFeeling(
    int feeling1, int feeling2, int feeling3, 
    int feeling4, int feeling5
) { 
    int greatestFeeling = 0;
    if (feeling1 > greatestFeeling) {
    greatestFeeling = feeling1;
    }
    if (feeling2 > greatestFeeling) {
    greatestFeeling = feeling2;
    } 
    if (feeling3 > greatestFeeling) {
    greatestFeeling = feeling3;
    }
    if (feeling4 > greatestFeeling) {
    greatestFeeling = feeling4;
    }
    if (feeling5 > greatestFeeling) {
    greatestFeeling = feeling5;
    }
    if (
        feeling1 == 0 && feeling2 == 0 && feeling3 == 0 && 
        feeling4 == 0 && feeling5 == 0
    ) {
    greatestFeeling = NONE;
    }
    return greatestFeeling;
}

void lonely() {
  printLonelyCat();
  printf("I'm sorry to hear that you're feeling lonely!\n");
  printf("When I'm lonely, I like to talk to someone.\n");
  printf("Some of my favourite ways to connect during\n");
  printf("quarantine are dating apps, speed friending events\n");
  printf("and family activities. Which would you like to do?\n\n");
  printf("Type 1 for dating apps recommendations.\n");
  printf("Type 2 for speed friending events.\n");
  printf("Type 3 for family activities.\n");
  // Activate the scan words function.
  int activityType = 0;
  scanf("%d", &activityType);

  if (activityType == 1) { // Dating apps
    printf("\nI love dating apps!\n");
    printf("They match me with heaps of groovy cats, who I can\n");
    printf("message fur-ever, and hopefully find a cat-ch!\n");
    printf("(plus a bit of eye candy along the way!)\n");
    printf("Here are a few links!\n");
    printf("Tinger: tinder.com\n");
    printf("Bumble: bumble.com\n");
    printf("OkCupid: okcupid.com\n");
  } else if (activityType == 2) { // Speed friending events
    printf("\nSpeed friending is paw-some!\n");
    printf("The best ones have fun activities like online poker,\n");
    printf("where you can flex your ELITE GAMER skills!!!\n");
    printf("Check facebook.com/ArcUNSW for upcoming events!\n");
  } else if (activityType == 3) { // Family Activities
    printf("\nFamily activities are a blast!\n");
    printf("Personally, I love a good board game, but you can also\n");
    printf("watch TV together, play sports and heaps more!\n");
    printf("If your fam is a cool cat like me, you could\n");
    printf("even try having a cocktail night!!! xD");
    cocktailRecipes();
  } else { // Invalid Input
    printf("\nSorry, I didn't quite catch that...\n");
  }
}

void cocktailRecipes() {
  printf("\nHere are some of my fav at-home cocktail recipies:\n");
  printf("Type 1 for Spiced Apple Jack\n");
  printf("Type 2 for Sex on the Beach\n");
  printf("Type 3 for Simple Cocktails\n");

  int cocktailType = 0;
  scanf("%d", &cocktailType);
  if (cocktailType == 1) {
    printf("\nJack Daniels' Spiced Apple Jack:\n\n");
    printf("INGREDIENTS:\n");
    printf("35ml Jack Daniel's Old No. 7®\n");
    printf("15 ml Amaretto® (or vodka)\n");
    printf("60 ml Apple juice\n");
    printf("Ginger beer\n\n");

    printf("INSTRUCTIONS:\n");
    printf("1. 3/4 fill a highball glass with cubed ice\n");
    printf("2. Pour Old No. 7 and Amaretto® over ice\n");
    printf("3. Add the apple juice and top with ginger beer\n");
    printf("4. Add lemon wedge to garnish\n");
  } else if (cocktailType == 2) {
    printf("\nSex on the Beach:\n\n");

    printf("INGREDIENTS:\n");
    printf("ice\n");
    printf("50ml vodka\n");
    printf("25ml peach schnapps\n");
    printf("2 oranges, juiced, plus 2 slices to garnish\n");
    printf("50ml cranberry juice\n");
    printf("glacé cherries, to garnish (optional)\n\n");

    printf("INSTRUCTIONS:\n");
    printf("1. Fill two tall glasses with ice cubes.\n");
    printf("2. Pour the vodka, peach schnapps and fruit juices\n");
    printf("into a large jug and stir.\n");
    printf("3. Divide the mixture between the two glasses and stir gently\n");
    printf("to combine.\n");
    printf("4. Garnish with the cocktail cherries and orange slices.\n");
      
  } else if (cocktailType == 3) { // Simple Cocktails
    printf("\nHere are some simple cocktails!\n\n");

    printf("Jack Daniels' Jack and Coke:\n\n");
    printf("INGREDIENTS:\n");
    printf("50 ml Jack Daniel's Old No. 7®\n");
    printf("Cola\n\n");

    printf("INSTRUCTIONS:\n");
    printf("3/4 fill a highball glass with cubed ice\n");
    printf("Pour Old No. 7 over ice\n");
    printf("Top with cola\n\n");

    
    printf("Captain Morgan's Rum and Coke:\n\n");
    printf("INGREDIENTS:\n");
    printf("50 ml Captain Morgan Original Spiced Gold\n");
    printf("125 ml Coke\n");
    printf("1 Wedge of lime\n");
    printf("1 Glassful of ice\n\n");

    printf("INSTRUCTIONS:\n");
    printf("Fill a tankard or tall glass with plenty of ice.\n");
    printf("Pour the Captain Morgan Original Spiced Gold and cola into the glass.\n");
    printf("Mix and garnish with your wedge of lime.\n");
    printf("Yo Ho Ho and all that!\n");
  }
}

void bored(void) {
    //insert bored cat image
    printf("\n");
    printf("   |\\---/| \n");
    printf("   | ,_, | \n");
    printf("    \\_`_/-..----. \n");
    printf(" ___/ `   ' ,""+ \\ \n");
    printf(" (__...'   __\\    |`.___.'; \n");
    printf("  (_,...'(_,.`__)/'.....+ \n");
    printf("\n");
    printf("Oh that sucks! When I'm bored, I like to play with my friends! \n");
    printf("Do you want to meet them? Type 0 for No and 1 for Yes:");
    int option = 0;
    scanf("%d", &option);
    //User chooses to meet cats friends
    if (option == 1) {
        printf("\n");
        printf("                       /^--^\\     /^--^\\     /^--^\\   ");
        printf("\n");
        printf("                       \\____/     \\____/     \\____/   ");
        printf("\n");
        printf("                      /      \\   /      \\   /      \\  ");
        printf("\n");
        printf("                     |        | |        | |        | ");
        printf("\n");
        printf("                      \\__  __/   \\__  __/   \\__  __/  ");
        printf("\n");
        printf(" |^|^|^|^|^|^|^|^|^|^|^|^\\ \\^|^|^|^/ /^|^|^|^|^\\ \\^|^|^|^|^|^|^|^|^|^|^|^| ");
        printf("\n");
        printf(" | | | | | | | | | | | | |\\ \\| | |/ /| | | | | |\\ \\ | | | | | | | | | | | ");
        printf("\n");
        printf(" ########################/ /######\\ \\###########/ /####################### ");
        printf("\n");
        printf(" | | | | | | | | | | | | \\/| | | | \\/| | | | | |\\/ | | | | | | | | | | | | ");
        printf("\n");
        printf(" |_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_| ");
        printf("\n");
        printf("I'm the cat in the middle! On the right is chicken and on the left is charlotte.\n");
        printf("Aren't they cute!");
        printf("\n");
        printf("Here are some things I like to do with Chicken and Charlotte.\n");
        printf("Pick one and I'll tell you more about it!");
        printf("\n");
        printf("Type 1 if you want to learn about activites you can do with YOUR friends!\n");
        printf("Type 2 if you want to learn about my favourite activity that you can do by yourself.\n");
        printf("Type 3 if you want to go on a spontaneous adventure with all three of us cats!\n");
        int option2 = 0;
        scanf("%d", &option2);
        if (option2 == 1) {
                printf("You should meet up with your friends!\n");
                printf("Here's a link to some awesome activities you can do with them during covid, including:\n");
                printf("- Have a backyard 'drive in'\n");
                printf("- Have a campfire in the backyard\n");
                printf("- Grill!\n");
                printf("Find more at: shorturl.at/jsMP8\n");
            } else if (option2 == 2) {
                printf("How about a fun activity you can do outside by yourself like cycling!\n");
                printf("Here's some tips for a safe day out: ");
                printf("\n");
                printf("1. Always wear a helmet! It would be pawful if you fell!");
                printf("\n");
                printf("2. Take a bottle of water :)");
                printf("\n");
                printf("3. Bring a repair kit incase you get a flat.");
                printf("\n");
                printf("4. Make sure your tires have enough air in them.");
                printf("\n");
        } else if (option2 == 3) {
            printf("Awesome! It's only going to be a short trip down the street, but it'll be fun!\n");
            printf("*You walk out your door and down your street, Chicken, Charlotte and Cat in tow*\n");
            printf("*A dog is coming the other way!*\n");
            printf("Press 0 to cross the street and avoid the inveitable clash! Press 1 if you dare...\n");
            int cross = 0;
            scanf("%d", &cross);
            if (cross == 0) { // you cross the street
                printf("*After a quick look over your shoulder, you hurry across the street.*\n");
            } else { // you DONT cross the street!!!
                printf("*Barking and hissing ensues! The dog barely escapes with his life,\n");
                printf("her owner gives you a dirty look...*\n");
            }
            printf("*Chicken, Charlotte and Cat Damon all look up at you lovingly. They are so cute!!*\n");
            printf("*You're already back at home! What a short but fun walk :)*\n");
        }

        } else {
            printf("Are you sure you want to feel the Wrath of Paw Daemon... \n");
            printf("(0 for No, 1 for Yes. IF YOU CONTINUE, PRESS CTRL-C TO EXIT!!\n");
            int scary = 0;
            scanf("%d", &scary);
            if (scary == 1) {
                int i = 0;
                while (i == 0) {
                printf("|\\---/|\n");
                printf("| o_o |\n");
                printf(" \\_^_/\n");
            }
        } else {
            printf("Cya!\n");
        }
    }
}

void stressed() {
    printf("\n");
    printTiredCat();
    printf("University can get pretty tough at times.\n");
    printf("But I'm there for you!\n");
    printf("We all feel Claw-ful sometimes, and I've got some resources to help,\n");
    printf("if you want to see?\n");
    
    
    //Randomly generates a number between 1 and 3 to choose method
    srand(time(0));
    int method = rand() % 4;
    
    int yes = 1;
    
    if (check_yes() > 0) {
        int num_ways = 0;
        while (num_ways < 3 && yes == 1) {
            yes = 0;
            //Lo-fi music
            if (method == 0) {
                printf("\nI find that lo-fi music helps me study, so maybe that will help you too!!\n");
                printf("In fact, you might even see me in the background!\n");
                printf("\n       ,-. __ .-,\n");
                printf("    --;`. '   `.'\n");
                printf("     / (  ^__^  )\n");
                printf("    ;   `(_`'_)' \\ \n");
                printf("    '  ` .`--'_,  ;\n");
                printf("  ~~`-..._)))(((.' \n\n"); 
                
                printf("Unfortunately I can't sing for you, so here's a link:\n");
                printf("*www.youtube.com/watch?v=5qap5aO4i9A*\n");
            
                if (num_ways < 2) {
                    printf("\nDid you want to see another way to destress? ");            
                    if (check_yes() > 0) {
                        method = 3;
                        yes = 1;
                    }
                }
            } else if (method == 1) {
                //Meditation
                printf("\nIf I just need a break, meditation is Purr-fect.\n");
                printf("This method can really help:\n");
                printf("First, find a nice place where you can relax, such as a comfy chair or bed.\n");
                printf("Make sure you're somewhere comfortable, where you can chill for a while.\n");
                /*Sleepy Cat*/
                printf("\n    /|      _,,,---,,_\n");
                printf("   /,`.-'`'    -.  ;-;;,_\n");
                printf("  |,4-  ) )-,_..; | (  `'-'\n");
                printf(" '---''(_/--'  `-'/_)  \n\n");
                
                printf("Now, start focusing on your breathing, counting as you breath in,\n");
                        printf("and counting when you breathe out. Keep on breathing for as long as\n");
                        printf("you want to, but a good start is to try this for 5 minutes.\n");
                printf("That exercise really keeps me calm when I need to be at my best,\n");
                        printf("so I hope it works the same for you!\n");
                if (num_ways < 2) {
                    printf("\nDid you want to see another way to destress? " );            
                    if (check_yes() > 0) {
                        method = 0;
                        yes = 1;
                    }
                }
            } else if (method == 2) {
                //Organisation
                printf("\nA good to-do list is always worthwhile!\n");
                printf("They always ensure I finish everything I need.\n");
                printf("\n         /|_|\\ \n");
                printf("    ____/ o o \\ \n");
                printf("  /~____  =o?= /\n");
                printf(" (______)__m_m)\n\n");
                printf("Here is the one I use! *todoist.com*\n");
                if (num_ways < 2) {
                    printf("Did you want to see another way to destress? ");            
                    if (check_yes() > 0) {
                        method = 1;
                        yes = 1;
                    }
                }
            } else if (method == 3) {
                printf("Another way to destress is a good drink.\n");
                cocktailRecipes();
                getchar();
                if (num_ways < 2) {
                    printf("Did you want to see another way to destress? " );            
                    if (check_yes() > 0) {
                        method = 2;
                        yes = 1;
                    }
                }
            }
            num_ways++;
        }
    } else { 
        printf("Oh well, I hope you feel better soon!\n");
    }

}


// Function that checks for yes
int check_yes(void) {
    //Checks to see if 0 is input
    int y_n = 0;
    char input[MAX_LINE_LENGTH];
    fgets(input, MAX_LINE_LENGTH, stdin);
    y_n += wordRecogCounter(input, "yes");
    y_n += wordRecogCounter(input, "yeah");
    y_n += wordRecogCounter(input, "yep");
    y_n += wordRecogCounter(input, "yup");
    y_n += wordRecogCounter(input, "ye");
    y_n += wordRecogCounter(input, "affirmative");
    y_n += wordRecogCounter(input, "y");
    return y_n;
}

// Function 
void sad(void) {
    printf("\n");
    printSadCat();
    
    printf("\nAw no don't be sad!\n");
    printf("There's so much to be happy about right now!!!\n");
    
    printf("I know what makes me feel better.\n\nType 1 for funny videos.\n");
    printf("Type 2 for fun food recipes.\n");
    printf("Type 3 for feel good articles.\n");
    
    int sadOption = 0;
    scanf("%d", &sadOption);
    if (sadOption == 1) {
        printf("Dwight Schrute LIFE LESSONS - The Office US:\n");
        printf("https://www.youtube.com/watch?v=aYWhDZurjSw\n\n");
        printf("Hamish and Andy - Drinking Magic Tea in Puru:\n");
        printf("https://www.youtube.com/watch?v=mAxEgmepd3o\n\n");
        printf("PewDiePie's channel: youtube.com/pewdiepie\n");

        printf("\nWould you like some more? ");
        if (check_yes() > 0) {
            printf("\nOkay! Here are some more of my favourites:\n");
            printf("\nBest Cat Videos: \nhttps://www.youtube.com/watch?v=pOmu0LtcI6Y\n");
            printf("\nRemember Vine? https://www.youtube.com/watch?v=BlZerAfwQE8\n");
        } 
    } else if (sadOption == 2) {
        printf("Type 1 for PewDiePie's Swedish Pancakes Recipe.\n");
        printf("Type 2 for some easy cocktail recipes!\n");
        
        int recipeType = 0;
        scanf("%d", &recipeType);
        if (recipeType == 1) {
            printf("\n%cSwedish%c pancakes recipe\n\n",'"','"');
         
            printf("Ingredients:\n\n");
            printf("Eggs\n");
            printf("Flour\n");
            printf("Butter\n");
            printf("Salt\n");
            printf("Milk\n");
            printf("Jam (optional)\n\n");

            printf("Method:\n\n");
            printf("Get a large bowl\n");
            printf("pour 2 100mL flour\n");
            printf("Crack 2 eggs\n");
            printf("Pour 400mL milk\n");
            printf("Sprinkle a Little bit of salt\n");
            printf("Whisk the ingredients together\n");
            printf("(make your dad proud)\n");
            printf("Warm up pan to medium heat\n");
            printf("Put some butter in the pan and spread it out evenly)\n");
            printf("Pour batter in from the center\n");
            printf("(enough to fill up the pan)\n");
            printf("They are not supposed to be thick\n");
            printf("Let it cook and flip when ready\n");
            printf("Put on plate and serve.\n");
        } else if (recipeType == 2) {
            cocktailRecipes();
        }
        
    } else if (sadOption == 3) {
        printf("\nHere are some feel good articles: \nhttps://www.goodnewsnetwork.org/\n");
        printf("\nAnd more: \nhttps://upliftconnect.com/our-most-inspiring-articles-of-the-year/\n");
    }
}

void printLonelyCat() {
    printf("\n");
    printf("               /\\____/\\    __\n"
    "             .'  %c%c%c%c  `,-'  `--.__\n"
    "        __,- :   -  -  ;  %c ::     `-. -.__\n"
    "     ,-sssss `._  `' _,'%c     ,'~~~::`.sssss-.\n"
    "    |ssssss ,' ,_`--'_    __,' ::  `  `.ssssss|\n"
    "   |sssssss `-._____~ `,,'_______,---_;; ssssss|\n"
    "    |ssssssssss     `--'~{__   ____   ,'ssssss|\n"
    "     `-ssssssssssssssssss ~~~~~~~~~~~~ ssss.-'\n"
    "          `---.sssssssssssssssssssss.---'\n", '"','"','"','"','"','"');
    printf("\n");
}