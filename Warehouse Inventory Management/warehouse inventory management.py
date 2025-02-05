class Warehouse:
    def __init__(self):
        self.inventory = {}

    def add_item(self, item_name, quantity, price):
        if item_name in self.inventory:
            self.inventory[item_name]['quantity'] += quantity
        else:
            self.inventory[item_name] = {'quantity': quantity, 'price': price}
        print(f"Added {quantity} of {item_name} to inventory.")

    def update_item(self, item_name, quantity=None, price=None):
        if item_name in self.inventory:
            if quantity is not None:
                self.inventory[item_name]['quantity'] = quantity
            if price is not None:
                self.inventory[item_name]['price'] = price
            print(f"Updated {item_name} in inventory.")
        else:
            print(f"Item {item_name} not found in inventory.")

    def remove_item(self, item_name):
        if item_name in self.inventory:
            del self.inventory[item_name]
            print(f"Removed {item_name} from inventory.")
        else:
            print(f"Item {item_name} not found in inventory.")

    def display_inventory(self):
        if not self.inventory:
            print("Inventory is empty.")
        else:
            print("\nWarehouse Inventory:")
            for item, details in self.inventory.items():
                print(f"{item}: Quantity: {details['quantity']}, Price: ${details['price']}")

# Example usage
if __name__ == "__main__":
    warehouse = Warehouse()
    while True:
        print("\n1. Add Item\n2. Update Item\n3. Remove Item\n4. Display Inventory\n5. Exit")
        choice = input("Enter your choice: ")
        if choice == '1':
            name = input("Enter item name: ")
            qty = int(input("Enter quantity: "))
            price = float(input("Enter price per unit: "))
            warehouse.add_item(name, qty, price)
        elif choice == '2':
            name = input("Enter item name to update: ")
            qty = input("Enter new quantity (leave blank to keep current): ")
            price = input("Enter new price (leave blank to keep current): ")
            warehouse.update_item(name, int(qty) if qty else None, float(price) if price else None)
        elif choice == '3':
            name = input("Enter item name to remove: ")
            warehouse.remove_item(name)
        elif choice == '4':
            warehouse.display_inventory()
        elif choice == '5':
            print("Exiting...")
            break
        else:
            print("Invalid choice. Please try again.")
