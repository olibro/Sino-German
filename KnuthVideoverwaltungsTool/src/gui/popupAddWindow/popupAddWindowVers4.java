package gui.popupAddWindow;

import javafx.application.Application;
import javafx.beans.value.ChangeListener;
import javafx.beans.value.ObservableValue;
import javafx.collections.FXCollections;
import javafx.collections.ListChangeListener;
import javafx.collections.ObservableList;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.stage.FileChooser;
import javafx.stage.Stage;
import tutorials.FileChooserSample;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.geometry.HPos;
import javafx.geometry.Insets;
import javafx.scene.control.Button;
import javafx.scene.control.CheckBox;
import javafx.scene.control.CheckBoxTreeItem;
import javafx.scene.control.Label;
import javafx.scene.control.RadioButton;
import javafx.scene.control.TextField;
import javafx.scene.control.Toggle;
import javafx.scene.control.ToggleButton;
import javafx.scene.control.ToggleGroup;
import javafx.scene.control.TreeItem;
import javafx.scene.effect.Lighting;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.scene.paint.Color;
import javafx.scene.text.Font;
import javafx.scene.text.Text;
import javafx.scene.control.TreeView;

import java.awt.Desktop;
import java.io.File;
import java.io.IOException;
import java.util.logging.Level;
import java.util.logging.Logger;

import org.controlsfx.control.CheckComboBox;
import org.controlsfx.control.CheckTreeView;

/**
 * A sample with a control that creates a decorated stage that is centered on
 * your desktop.
 *
 * @see javafx.stage.Stage
 * @see javafx.scene.Scene
 */
public class popupAddWindowVers4 {
	
    private Desktop desktop = Desktop.getDesktop();
	final Stage popupAdd = new Stage();


	public popupAddWindowVers4(Stage primaryStage) {
		// create root node of scene, i.e. group
		Group rootGroup = new Group();
		// create scene with set width, height
		Scene scene = new Scene(rootGroup, 900, 600);
		// set scene to stage
		popupAdd.setScene(scene);
		// center stage on screen
		popupAdd.centerOnScreen();
		// show the stage
		final BorderPane allScenes = new BorderPane();

		allScenes.setTop(topHBoxScene());
		allScenes.setLeft(leftHBoxScene());
		allScenes.setRight(rightHBoxScene());

		rootGroup.getChildren().addAll(allScenes);
		popupAdd.show();
	}

	private HBox topHBoxScene() {
		HBox hbox = new HBox();
		hbox.setPadding(new Insets(15, 12, 15, 12));
		hbox.setSpacing(10); // Gap between nodes
		hbox.setStyle("-fx-background-color: #666666;");

		hbox.getChildren().addAll(new AddSearchBox(), getIMDBSerachButton());

		return hbox;
	}

	private VBox leftHBoxScene() {
		VBox vbox = new VBox();
		vbox.setPadding(new Insets(15, 12, 15, 12));
		vbox.setSpacing(10); // Gap between nodes
		vbox.setStyle("-fx-background-color: #555555;");

		vbox.getChildren().add(getInformationScene());

		return vbox;
	}

	private VBox rightHBoxScene() {
		VBox vbox = new VBox();
		vbox.setPadding(new Insets(15, 12, 15, 12));
		vbox.setSpacing(10); // Gap between nodes
		vbox.setStyle("-fx-background-color: #336699;");

		// HBox languageBox = addCheckTreeViewLanguage();
		// HBox languageBox = addCheck();

		vbox.getChildren().add(getCategories());
		vbox.getChildren().add(getLanguageCheckComboBox());
		return vbox;
	}

	private VBox addCheckBoxesGenre() {
		VBox vbox = new VBox();
		vbox.setPadding(new Insets(15, 12, 15, 12));
		vbox.setSpacing(10); // Gap between nodes
		vbox.setStyle("-fx-background-color: #336699;");

		// add some node to scene

		Text text = new Text(20, 110, "JavaFX");

		Button btnAddTitle = new Button("Titel Hinzufügen");
		// add text to the main root group

		vbox.getChildren().addAll(text, btnAddTitle);
		return vbox;
	}

	private VBox getCategories() {
		VBox vbox = new VBox();
		HBox hbox = new HBox();

		ToggleGroup group = new ToggleGroup();

		hbox.setSpacing(5); // Gap between nodes
		vbox.setPadding(new Insets(15, 12, 15, 12));
		vbox.setSpacing(5); // Gap between nodes
		vbox.setStyle("-fx-background-color: #336699;");

		Label label = new Label("Kategorie");

		RadioButton rb1 = new RadioButton("Filme");
		rb1.setSelected(true);
		rb1.setToggleGroup(group);
		rb1.setStyle("-fx-font-size: 14px");

		RadioButton rb2 = new RadioButton("Serien");
		rb2.setToggleGroup(group);
		rb2.setStyle("-fx-font-size: 14px");

		hbox.getChildren().addAll(rb1, rb2);
		vbox.getChildren().addAll(label, hbox);

		return vbox;
	}

	
	// gibt je nach auswahl(Loca/OnDemand/Bib) einen Textfeld, Tf mit Hyperlink
	// oder File Choser Button zurück
	private GridPane getLocationScene() {
		
		
		GridPane gridPane = new GridPane();
		GridPane variablegridPane = new GridPane();

		gridPane.setGridLinesVisible(true);
		variablegridPane.setGridLinesVisible(true);

		gridPane.setVgap(4);
		gridPane.setHgap(20);

		
		boolean bib = false;
		boolean localHDD = false;
		boolean onDemand = false;

		FileChooser fileChooser = new FileChooser();
		fileChooser.setTitle("Open Resource File");
		// fileChooser.showOpenDialog(stage);

		ToggleGroup group = new ToggleGroup();

		RadioButton rbBib = new RadioButton("Bücher Regal");
		RadioButton rbLocalHDD = new RadioButton("Auf Festplatte");
		RadioButton rbOnDemand = new RadioButton("OnDemand");
		
		TextField tfBib = new TextField("Regal");
		tfBib.setPrefSize(280, 0);
		TextField tfOnDemand = new TextField("http://");
		tfOnDemand.setPrefSize(280, 0);
		TextField tfLocalHDD = new TextField(System.getProperty("user.home"));
		tfLocalHDD.setPrefSize(280, 0);
		Button openButton = new Button("Öffnen");
		
		openButton.setOnAction(
	            new EventHandler<ActionEvent>() {
	                @Override
	                public void handle(final ActionEvent e) {
	                    File file = fileChooser.showOpenDialog(popupAdd);
	                    if (file != null) {
	                        openFile(file);
	                    }
	                }
	            });

//        openButton.setOnAction(
//                new EventHandler<ActionEvent>() {
//                    @Override
//                    public void handle(final ActionEvent e) {
//                        File file = fileChooser.showOpenDialog(popupAdd);
//                        if (file != null) {
//                            openFile(file);
//                        }
//                    }
//                });

		rbBib.setToggleGroup(group);
//		rbBib.setSelected(true);
		rbLocalHDD.setToggleGroup(group);
		rbOnDemand.setToggleGroup(group);
		
		
		group.selectedToggleProperty().addListener(new ChangeListener<Toggle>(){
		    public void changed(ObservableValue<? extends Toggle> ov,
		            Toggle old_toggle, Toggle new_toggle) {
		    	if (group.getSelectedToggle() != null) {
		    		if(group.getSelectedToggle() == rbBib){
		    			variablegridPane.getChildren().remove(tfOnDemand);
		    			variablegridPane.getChildren().remove(tfLocalHDD);
		    			variablegridPane.getChildren().remove(openButton);

		    			variablegridPane.add(tfBib, 0, 0);
		    		}
		    		if(group.getSelectedToggle() == rbOnDemand){
		    			variablegridPane.getChildren().remove(tfBib);
		    			variablegridPane.getChildren().remove(tfLocalHDD);
		    			variablegridPane.getChildren().remove(openButton);
		    			variablegridPane.add(tfOnDemand, 0, 0);
		    		}
		    		if (group.getSelectedToggle() == rbLocalHDD){
		    			variablegridPane.getChildren().remove(tfBib);
		    			variablegridPane.getChildren().remove(tfOnDemand);
		    			variablegridPane.add(tfLocalHDD, 0, 0);
		    			variablegridPane.add(openButton, 0, 1);
		    			GridPane.setHalignment(openButton, HPos.RIGHT);
		    		}
		    		
		    	}
		    }
		});
		
		gridPane.add(rbBib, 0, 0);
		gridPane.add(rbLocalHDD, 0, 1);
		gridPane.add(rbOnDemand, 0, 2);
		gridPane.add(variablegridPane, 1, 0, 3, 3);
		
		
		

		return gridPane;

	}
	
	private void openFile(File file) {
        try {
            desktop.open(file);
        } catch (IOException ex) {
            Logger.getLogger(
                FileChooserSample.class.getName()).log(
                    Level.SEVERE, null, ex
                );
        }
    }

	private GridPane getFSKImages() {
		GridPane gridPane = new GridPane();
		gridPane.setHgap(16);


		Image ICON_FSK00 = new Image(AddSearchBox.class.getResourceAsStream("FSK-0.png"));
		Image ICON_FSK06 = new Image(AddSearchBox.class.getResourceAsStream("FSK-6.png"));
		Image ICON_FSK12 = new Image(AddSearchBox.class.getResourceAsStream("FSK-12.png"));
		Image ICON_FSK16 = new Image(AddSearchBox.class.getResourceAsStream("FSK-16.png"));
		Image ICON_FSK18 = new Image(AddSearchBox.class.getResourceAsStream("FSK-18.png"));

		ImageView fsk00 = new ImageView(ICON_FSK00);
		ImageView fsk06 = new ImageView(ICON_FSK06);
		ImageView fsk12 = new ImageView(ICON_FSK12);
		ImageView fsk16 = new ImageView(ICON_FSK16);
		ImageView fsk18 = new ImageView(ICON_FSK18);

		ToggleButton tbFSK00 = new ToggleButton("", fsk00);
		ToggleButton tbFSK06 = new ToggleButton("", fsk06);
		ToggleButton tbFSK12 = new ToggleButton("", fsk12);
		ToggleButton tbFSK16 = new ToggleButton("", fsk16);
		ToggleButton tbFSK18 = new ToggleButton("", fsk18);

		// tbFSK0.setStyle(value);

		gridPane.add(tbFSK00, 0, 0);
		gridPane.add(tbFSK06, 1, 0);
		gridPane.add(tbFSK12, 2, 0);
		gridPane.add(tbFSK16, 3, 0);
		gridPane.add(tbFSK18, 4, 0);

		return gridPane;

	}

	private GridPane getInformationScene() {
		GridPane gridPane = new GridPane();
		gridPane.setPadding(new Insets(10, 10, 10, 10));
		gridPane.setHgap(7);
		gridPane.setVgap(7);
		gridPane.setStyle("-fx-background-color: #999999;");
		// gridPane.setGridLinesVisible(true);

		Label lTitel = new Label("Titel:");
		Label lOriginTitel = new Label("Orginal Titel:");
		Label lPlaytime = new Label("Laufzeit");
		Label lMin = new Label("min  ");
		Label lYear = new Label("Jahr");
		Label lTrailer = new Label("Trailer:");
		Label lStudio = new Label("Studio");
		Label lRegiseur = new Label("Regiseur");
		Label lLocation = new Label("Standort:");
		Label lFSK = new Label("FSK:");
		Label lGesehen = new Label("Gesehen:");
		TextField tfTitel = new TextField();
		TextField tfOriginTitel = new TextField();
		TextField tfLocation = new TextField();
		TextField tfPlaytime = new TextField();
		TextField tfYear = new TextField();
		TextField tfTrailer = new TextField();
		TextField tfStudio = new TextField();
		TextField tfRegiseur = new TextField();

		CheckBox cbGesehen = new CheckBox();

		// add(element, breite, höhe / breitenspanne / höhenspanne)
		gridPane.add(lTitel, 0, 0);
		gridPane.add(tfTitel, 1, 0, 4, 1);

		gridPane.add(lOriginTitel, 0, 1);
		gridPane.add(tfOriginTitel, 1, 1, 4, 1);

		gridPane.add(lPlaytime, 0, 2);
		gridPane.add(tfPlaytime, 1, 2);

		gridPane.add(lYear, 0, 3);
		gridPane.add(tfYear, 1, 3);

		gridPane.add(lTrailer, 0, 4);
		gridPane.add(tfTrailer, 1, 4);

		gridPane.add(lMin, 2, 2);
		gridPane.add(lStudio, 3, 2);
		gridPane.add(tfStudio, 4, 2);

		gridPane.add(lRegiseur, 3, 3);
		gridPane.add(tfRegiseur, 4, 3);

		gridPane.add(lGesehen, 3, 4);
		gridPane.add(cbGesehen, 4, 4);
		gridPane.add(lFSK, 0, 5);
		gridPane.add(getFSKImages(), 1, 5, 4, 1);
		gridPane.add(lLocation, 0, 6);
		gridPane.add(getLocationScene(), 1, 6, 4, 1);

		return gridPane;

	}

	private HBox addCheckTreeViewLanguage() {
		HBox hbox = new HBox();

		// create the data to show in the CheckTreeView
		CheckBoxTreeItem<String> languageSelections = new CheckBoxTreeItem<String>("Sprachen");
		languageSelections.setExpanded(true);
		languageSelections.getChildren().addAll(new CheckBoxTreeItem<String>("Englisch"),
				new CheckBoxTreeItem<String>("Französisch"), new CheckBoxTreeItem<String>("Deutsch"),
				new CheckBoxTreeItem<String>("Spanisch"), new CheckBoxTreeItem<String>("Türkisch"),
				new CheckBoxTreeItem<String>("Arabisch"), new CheckBoxTreeItem<String>("Russisch"),
				new CheckBoxTreeItem<String>("Portugiesisch"), new CheckBoxTreeItem<String>("Japanisch"),
				new CheckBoxTreeItem<String>("Koreanisch"));

		// Create the CheckTreeView with the data
		final CheckTreeView<String> checkTreeView = new CheckTreeView<>(languageSelections);

		// and listen to the relevant events (e.g. when the checked items
		// change).
		checkTreeView.getCheckModel().getCheckedItems().addListener(new ListChangeListener<TreeItem<String>>() {
			public void onChanged(ListChangeListener.Change<? extends TreeItem<String>> c) {
				System.out.println(checkTreeView.getCheckModel().getCheckedItems());
			}
		});

		hbox.getChildren().add(checkTreeView);
		return hbox;
	}

	private HBox getLanguageCheckComboBox() {
		HBox hbox = new HBox();

		final ObservableList<String> strings = FXCollections.observableArrayList();

		strings.addAll("Englisch", "Französisch", "Deutsch", "Spanisch", "Türkisch", "Arabisch", "Russisch",
				"Portugiesisch", "Japanisch", "Koreanisch");

		// create the data to show
		CheckComboBox<String> checkComboBox = new CheckComboBox<String>(strings);

		// and listen to the relevant events (e.g. when the checked items
		// change).
		checkComboBox.getCheckModel().getCheckedItems().addListener(new ListChangeListener<String>() {
			public void onChanged(ListChangeListener.Change<? extends String> c) {
				System.out.println(checkComboBox.getCheckModel().getCheckedItems());
			}
		});

		hbox.getChildren().add(checkComboBox);
		return hbox;

	}

	private HBox getIMDBSerachButton() {
		HBox hbox = new HBox();
		Image ICON_IMDB = new Image(popupAddWindowVers4.class.getResourceAsStream("imdb_small.png"));
		ImageView imageViewIMDB = new ImageView(ICON_IMDB);
		// mit Icon
		// Button btnAddFromIMDB = new Button("Add from IMDB Database",
		// imageViewIMDB);
		// ohne Icon
		Button btnAddFromIMDB = new Button("Add from IMDB Database");

		hbox.getChildren().addAll(btnAddFromIMDB);
		return hbox;

	}

}
