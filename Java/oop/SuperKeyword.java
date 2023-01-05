package oop;

class Bicycle {
    String define_me() {
        return "a vehicle with pedals.";
    }
}

class Motorcycle extends Bicycle {
    Motorcycle() {
        System.out.println("Hello I am a motorcycle, I am " + define_me());
        String temp = super.define_me();
        System.out.println("My ancestor is a cycle who is " + temp);
    }

    String define_me() {
        return "a cycle with an engine.";
    }

}

class SuperKeyword {
    public static void main(String[] args) {
        //noinspection unused
        Motorcycle M = new Motorcycle();
    }
}
