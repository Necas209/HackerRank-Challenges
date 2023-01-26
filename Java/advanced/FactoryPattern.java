package advanced;

import java.io.Serial;
import java.security.Permission;
import java.util.Scanner;

interface Food {
    String getType();
}

class Pizza implements Food {
    public String getType() {
        return "Someone ordered a Fast Food!";
    }
}

class Cake implements Food {

    public String getType() {
        return "Someone ordered a Dessert!";
    }
}

class FoodFactory {
    public Food getFood(String order) {
        {
            if (order.equals("pizza")) {
                return new Pizza();
            } else if (order.equals("cake")) {
                return new Cake();
            } else {
                return null;
            }
        }
    }
}//End of factory class

public class FactoryPattern {
    public static void main(String[] args) {
        Do_Not_Terminate.forbidExit();
        try {
            Scanner sc = new Scanner(System.in);
            //creating the factory
            FoodFactory foodFactory = new FoodFactory();
            //factory instantiates an object
            Food food = foodFactory.getFood(sc.nextLine());
            System.out.println("The factory returned " + food.getClass());
            System.out.println(food.getType());
        } catch (Do_Not_Terminate.ExitTrappedException e) {
            System.out.println("Unsuccessful Termination!!");
        }
    }

}

@SuppressWarnings("removal")
class Do_Not_Terminate {
    public static void forbidExit() {
        final SecurityManager securityManager = new SecurityManager() {
            @Override
            public void checkPermission(Permission permission) {
                if (permission.getName().contains("exitVM")) {
                    throw new ExitTrappedException();
                }
            }
        };
        System.setSecurityManager(securityManager);
    }

    public static class ExitTrappedException extends SecurityException {
        @Serial
        private static final long serialVersionUID = 1L;
    }
}