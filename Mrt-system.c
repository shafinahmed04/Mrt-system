#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Customer {
    char username[50];
    char password[50];
    char name[100];
    int mrtPass;
};


void registerUser();
void loginUser();
void updateDetails();
void deleteAccount();
void applyForCard();
void getMRTPass();
void returnPass();


struct Customer customers[100];
int totalCustomers = 0;

int main() {
    int choice;

    do {
        printf("\nMetro MRT System\n");
        printf("1. Register\n");
        printf("2. Login\n");
        printf("3. Update Details\n");
        printf("4. Delete Account\n");
        printf("5. Apply for Card\n");
        printf("6. Get MRT Pass\n");
        printf("7. Return Pass\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                updateDetails();
                break;
            case 4:
                deleteAccount();
                break;
            case 5:
                applyForCard();
                break;
            case 6:
                getMRTPass();
                break;
            case 7:
                returnPass();
                break;
            case 8:
                printf("Exiting the Metro MRT System. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 8);

    return 0;
}

//added registeruser

void registerUser() {
    struct Customer newCustomer;
    printf("\nRegistration\n");
    printf("Enter username: ");
    scanf("%s", newCustomer.username);
    printf("Enter password: ");
    scanf("%s", newCustomer.password);
    printf("Enter your full name: ");
    getchar(); // Clear the newline character left in the buffer
    fgets(newCustomer.name, sizeof(newCustomer.name), stdin);
    newCustomer.name[strcspn(newCustomer.name, "\n")] = '\0'; // Remove newline character from the name
    newCustomer.mrtPass = 0;

    customers[totalCustomers++] = newCustomer;
    printf("Registration successful!\n");
}
