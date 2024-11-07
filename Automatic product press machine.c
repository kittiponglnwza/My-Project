#include <stdio.h>

struct Product {
    char name[50];
    float price;
};

void displayProducts(struct Product *products, int size) {
int i;
    printf("\nChoose your art toys:\n");
    for (i = 0; i < size; i++) {
        printf("%d. %s price %.2f baht\n", i + 1, products[i].name, products[i].price);
    }
}

float calculateTotal(struct Product *products, int *cart, int cartSize) {
int i;
    float total = 0.0;
    for (i = 0; i < cartSize; i++) {
        total += (*(products + cart[i])).price; 
    }
    return total;
}
float giftWrapping(float *total) {
    int wrappingOption;
    printf("\nWould you like to add gift wrapping for an additional 50.00 THB? (1 for yes, 0 for no): ");
    scanf("%d", &wrappingOption);
    
    if (wrappingOption == 1) {
        *total += 50.00;  
        printf("\nGift wrapping added. An additional 50.00 THB will be charged.\n\n");
    } else if (wrappingOption==0){
    printf("\nNo gift wrapping selected!\n");
} else {
printf("\nInvalid option. No gift wrapping selected.\n\n");
}
    return *total;
}

int main() {
    struct Product products[5] = {
        {"Labubu", 1250.00},
        {"Crybaby", 350.00},
        {"Molly", 700.00},
        {"Ahirono", 600.00},
        {"Angel baby", 790.00}
    };
    
    int cart[10]; 
    int cartSize = 0; 
    int choice;
    float money, total,paid;

    while (1) {
        displayProducts(products, 5); 
        printf("Choose number (Choose 0 for stop): ");
        scanf("%d", &choice);
        
        if (choice == 0) {
            break;
        } else if (choice > 0 && choice <= 5 && cartSize < 10) {
            cart[cartSize++] = choice - 1; 
            printf("Added product: %s\n", products[choice - 1].name);
        } else {
            printf("\nChoose the wrong product or cart is full, try again!\n");
        }
    }

    total = calculateTotal(products, cart, cartSize);
    printf("\nTotal price before gift wrapping: %.2f THB\n", total);

    total = giftWrapping(&total);  
    printf("Total price after gift wrapping: %.2f THB\n", total);

    while (paid < total){
    printf("\nPlease enter the payment amount: ");
    scanf("%f", &money);
    paid += money;
    if(paid >= total){
    printf("Payment successful! your change %.2f THB\n", paid-total);
}else {
printf("\nInsufficient funds!\n");
printf("\nPlease add more %.2f THB\n",total - paid);
}
    
}

    return 0;
}
