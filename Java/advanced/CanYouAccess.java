package advanced;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.Serial;
import java.security.Permission;


public class CanYouAccess {
    public static void main(String[] args) throws Exception {
        DoNotTerminate.forbidExit();
        try {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            int num = Integer.parseInt(br.readLine().trim());
            Inner.Private o = new Inner.Private();
            System.out.println(num + " is " + o.powerOfTwo(num));
            System.out.println("An instance of class: " + o.getClass().getCanonicalName() + " has been created");

        }//end of try

        catch (DoNotTerminate.ExitTrappedException e) {
            System.out.println("Unsuccessful Termination!!");
        }
    }//end of main

    static class Inner {
        private static class Private {
            private String powerOfTwo(int num) {
                return ((num & num - 1) == 0) ? "power of 2" : "not a power of 2";
            }
        }
    }//end of Inner

}//end of Solution

@SuppressWarnings("removal")
class DoNotTerminate { //This class prevents exit(0)
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

