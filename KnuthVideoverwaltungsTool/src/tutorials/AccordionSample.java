package tutorials;

/**
 * Copyright (c) 2008, 2012 Oracle and/or its affiliates.
 * All rights reserved. Use is subject to license terms.
 */
import javafx.application.Application;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.stage.Stage;
import javafx.scene.control.Accordion;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TitledPane;
import javafx.scene.paint.Color;
import javafx.scene.shape.Rectangle;
import javafx.scene.text.Text;

/**
 * An example of an accordion control. You can use accordion controls to define
 * individual panes and  display them one at a time.
 *
 * @see javafx.scene.control.Accordion
 * @related controls/buttons/ToggleButton
 * @related controls/toolbar/ToolBar
 */
public class AccordionSample extends Application {

    private void init(Stage primaryStage) {
        Group root = new Group();
        primaryStage.setResizable(false);
        primaryStage.setScene(new Scene(root, 150,150));
        TitledPane t1 = new TitledPane("Node 1", new Button("Button"));
        TitledPane t2 = new TitledPane("Node 2", new Text("String"));
        TitledPane t3 = new TitledPane("Node 3", new Rectangle(120,50, Color.RED));
        Accordion accordion = new Accordion();
        accordion.getPanes().add(t1);
        accordion.getPanes().add(t2);
        accordion.getPanes().add(t3);
        root.getChildren().add(accordion);
    }

    public double getSampleWidth() { return 150; }

    public double getSampleHeight() { return 150; }

    @Override public void start(Stage primaryStage) throws Exception {
        init(primaryStage);
        primaryStage.show();
    }
    public static void main(String[] args) { launch(args); }
}

