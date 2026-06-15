def main():
    print("=== Temperature Converter ===")
    try:
        celsius = float(input("Enter temperature in Celsius: "))
        fahrenheit = (celsius * 9/5) + 32
        print(f"{celsius}°C is equal to {fahrenheit}°F")
    except ValueError:
        print("Please enter a valid number!")

if __name__ == "__main__":
    main()

