package tutorials;

/**
 * Copyright (c) 2008, 2012 Oracle and/or its affiliates.
 * All rights reserved. Use is subject to license terms.
 */
import javafx.application.Application;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.stage.Stage;
import javafx.scene.control.RadioButton;
import javafx.scene.control.ToggleGroup;
import javafx.scene.layout.VBox;

/**
 * Radio buttons in various states.
 *
 * @see javafx.scene.control.RadioButton
 * @related controls/buttons/CheckBoxes
 * @related controls/buttons/GraphicButton
 */

public class RadioButtons extends Application {
    
    private void init(Stage primaryStage) {
        Group root = new Group();
        primaryStage.setResizable(false);
        primaryStage.setScene(new Scene(root, 400,100));
        ToggleGroup tg = new ToggleGroup();
        VBox vbox = new VBox();
        vbox.setSpacing(5);
        RadioButton rb1 = new RadioButton("Hello");
        rb1.setToggleGroup(tg);

        RadioButton rb2 = new RadioButton("Bye");
        rb2.setToggleGroup(tg);
        rb2.setSelected(true);

        RadioButton rb3 = new RadioButton("Disabled");
        rb3.setToggleGroup(tg);
        rb3.setSelected(false);
        rb3.setDisable(true);

        vbox.getChildren().add(rb1);
        vbox.getChildren().add(rb2);
        vbox.getChildren().add(rb3);
        root.getChildren().add(vbox);
    }

    public double getSampleWidth() { return 400; }

    public double getSampleHeight() { return 100; }

    @Override public void start(Stage primaryStage) throws Exception {
        init(primaryStage);
        primaryStage.show();
    }
    public static void main(String[] args) { launch(args); }
}

