package tutorials;

/**
 * Copyright (c) 2008, 2012 Oracle and/or its affiliates.
 * All rights reserved. Use is subject to license terms.
 */
import javafx.application.Application;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.stage.Stage;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.control.Button;
import javafx.scene.effect.Lighting;
import javafx.scene.paint.Color;
import javafx.scene.text.Font;
import javafx.scene.text.Text;

/**
 * A sample with a control that creates a decorated stage that is centered on
 * your desktop.
 *
 * @see javafx.stage.Stage
 * @see javafx.scene.Scene
 */
public class StageSample extends Application {
    
    private void init(Stage primaryStage) {
        Group root = new Group();
        primaryStage.setScene(new Scene(root));
        //create a button for initializing our new stage
        Button button = new Button("Create a Stage");
        button.setStyle("-fx-font-size: 24;");
        button.setDefaultButton(true);
        button.setOnAction(new EventHandler<ActionEvent>() {
            @Override public void handle(ActionEvent t) {
                final Stage stage = new Stage();
                //create root node of scene, i.e. group
                Group rootGroup = new Group();
                //create scene with set width, height and color
                Scene scene = new Scene(rootGroup, 200, 200, Color.WHITESMOKE);
                //set scene to stage
                stage.setScene(scene);
                //center stage on screen
                stage.centerOnScreen();
                //show the stage
                stage.show();
                //add some node to scene
                Text text = new Text(20, 110, "JavaFX");
                text.setFill(Color.DODGERBLUE);
                text.setEffect(new Lighting());
                text.setFont(Font.font(Font.getDefault().getFamily(), 50));
                //add text to the main root group
                rootGroup.getChildren().add(text);
            }
        });
        root.getChildren().add(button);
    }

    @Override public void start(Stage primaryStage) throws Exception {
        init(primaryStage);
        primaryStage.show();
    }
    public static void main(String[] args) { launch(args); }
}

