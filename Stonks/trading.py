import argparse

parser = argparse.ArgumentParser()
parser.add_argument("--money", type=int, default=0, help='Starting money for trade')
parser.add_argument("--stock_price", type=float, default=0, help='Starting price for stock')
parser.add_argument("--new_stock_price", type=float, default=0, help='Starting price for stock')
parser.add_argument("--ROI", action='store_true', default=False, help='Calculate ROI')
args = parser.parse_args()

def StockOptions(money: int, stock_price: float):
    print("At 100 percent of your cash, you can buy {} stocks".format(int(money / stock_price)))
    print("At 75 percent of your cash, you can buy {} stocks".format(int((money*.75) / stock_price)))
    print("At 50 percent of your cash, you can buy {} stocks".format(int((money*.50) / stock_price)))
    print("At 25 percent of your cash, you can buy {} stocks".format(int((money*.25) / stock_price)))

def calculateROI(old_price: float, new_price: float):
    average_tax = 10.00
    money_sunk = int(input("How many stocks did you buy?"))
    
    ROI = (money_sunk * new_price - average_tax ) - (money_sunk * old_price) 
    print("ROI is ${}".format(ROI))





if __name__ == "__main__":
    if args.ROI:
        old_price = args.stock_price
        new_price = args.new_stock_price
        calculateROI(old_price, new_price)
    else:    
        money = args.money
        stock_price = args.stock_price
        StockOptions(money, stock_price)