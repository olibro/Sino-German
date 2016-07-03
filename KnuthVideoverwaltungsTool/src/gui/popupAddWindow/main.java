package gui.popupAddWindow;

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
public class main extends Application {

	private void init(Stage primaryStage) {
		Group root = new Group();
		primaryStage.setScene(new Scene(root));
		// create a button for initializing our new stage
		Button button = new Button("Add");
		button.setDefaultButton(true);
		button.setOnAction(new EventHandler<ActionEvent>() {
			@Override
			public void handle(ActionEvent t) {
				popupAddWindowVers5 popupAdd = new popupAddWindowVers5(primaryStage);
			}
		});
		root.getChildren().add(button);
	}

	@Override
	public void start(Stage primaryStage) throws Exception {
		init(primaryStage);
		primaryStage.show();
	}

	public static void main(String[] args) {
		launch(args);
	}
}
