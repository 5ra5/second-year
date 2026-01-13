# All 3 parts included

class BankAccount(object):
    def __init__(self, name, surname, iban, balance=0):
        self.name = name
        self.surname = surname
        self.iban = iban
        self.balance = balance
        self.type = "Bank Account"
        self.rate = 0

    def deposit(self, amount):
        self.balance += amount
        return self.balance

    def withdraw(self, amount):
        self.balance -= amount

    def get_account_type(self):
        return self.type

    def apply_interest(self, rate):
        self.rate = rate

    def get_balance(self):
        return self.balance + (self.balance * self.rate)


# account1 = BankAccount("John", "Smith", "20044357", "johnsmith@gmail.com", 50)
# account2 = BankAccount("Petra", "Satori", "47538465", "petrasartori@gmail.com", 100)
# print(account1.deposit(100))
# print(account2.withdraw(50))
# print(account1.get_balance())
# print(account2.get_balance())

class SavingsAccount(BankAccount):

    def __init__(self, name, surname, iban, balance=0):
        super().__init__(name, surname, iban, balance)
        self.type = "Savings Account"

class CurrentAccount(BankAccount):

    def __init__(self, name, surname, iban, balance=0):
        super().__init__(name, surname, iban, balance)
        self.type = "Current Account"

    def overdraft(self, amount):
        limit = -150
        if self.balance - amount < limit:
            return "Overdraft limit is 150 euros!"
        else:
            self.withdraw(amount)
            return self.balance


# account = BankAccount("Joe", "Bloggs", 0)
# savings_account = SavingsAccount("Peter", "Jones", 0)
# current_account = CurrentAccount("Jane", "Doe", 0)

# print(account.get_account_type())
# print(savings_account.get_account_type())

# savings_account.apply_interest(.02)
# current_account.apply_interest(.01)

# savings_account.deposit(100)
# current_account.deposit(500)

# print(savings_account.get_balance())
# print(current_account.get_balance())
