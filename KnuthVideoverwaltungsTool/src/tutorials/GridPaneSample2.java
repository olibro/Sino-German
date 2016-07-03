package tutorials;

/**
 * Copyright (c) 2008, 2012 Oracle and/or its affiliates.
 * All rights reserved. Use is subject to license terms.
 */
import javafx.application.Application;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.stage.Stage;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.geometry.HPos;
import javafx.geometry.Insets;
import javafx.scene.Node;
import javafx.scene.control.Button;
import javafx.scene.control.CheckBox;
import javafx.scene.control.Label;
import javafx.scene.control.PasswordField;
import javafx.scene.control.Separator;
import javafx.scene.control.TextField;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.layout.*;

/**
 * An example of a GridPane layout. There is more than one approach to using a
 * GridPane. First, the code can specify which rows and/or columns should
 * contain the content. Second, the code can alter the constraints of the rows
 * and/or columns themselves, either by specifying the preferred minimum or
 * maximum heights or widths, or by specifying the percentage of the GridPane
 * that belongs to certain rows or columns.
 * 
 * @see javafx.scene.layout.GridPane
 * @related controls/text/SimpleLabel
 * @resource icon-48x48.png
 */
public class GridPaneSample2 extends Application {

	@Override
	public void start(Stage primaryStage) throws Exception {
		primaryStage.show();

		final GridPane gridPane = new GridPane();
		gridPane.setPadding(new Insets(10, 10, 10, 10));
		gridPane.setHgap(7);
		gridPane.setVgap(7);
		final Label lblName = new Label("Name:");
		final TextField tfName = new TextField();
		final Label lblPassword = new Label("Password:");
		final PasswordField pfPassword = new PasswordField();
		final Button btnLogin = new Button("Login");
		// Bereitstellung von Gitterlinien
		final CheckBox checkBoxShowGridLines = new CheckBox("Show Gridlines");
		checkBoxShowGridLines.setOnAction(new EventHandler<ActionEvent>() {
			@Override
			public void handle(final ActionEvent event) {
				gridPane.setGridLinesVisible(checkBoxShowGridLines.isSelected());
			}
		});
		// Zuordnung zum Grid (Node,X-Position, Y-Position)
		gridPane.add(lblName, 0, 0);
		gridPane.add(tfName, 1, 0);
		gridPane.add(lblPassword, 0, 1);
		gridPane.add(pfPassword, 1, 1);
		gridPane.add(btnLogin, 1, 2);
		gridPane.add(checkBoxShowGridLines, 0, 5);

		// Layoutbesonderheiten
		GridPane.setHalignment(lblName, HPos.LEFT);
		GridPane.setHalignment(lblPassword, HPos.RIGHT);
		GridPane.setHalignment(btnLogin, HPos.RIGHT);
		primaryStage.setScene(new Scene(gridPane, 300, 150));
		primaryStage.setTitle("GridPaneExample");
		primaryStage.show();
	}

	public static void main(String[] args) {
		launch(args);
	}
}
