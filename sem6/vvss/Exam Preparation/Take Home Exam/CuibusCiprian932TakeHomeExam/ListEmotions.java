import java.lang.reflect.Array;
import java.util.*;
import java.util.stream.Collectors;

public class ListEmotions {

    private List<Emotion> lstEmotions;

    public ListEmotions(List<Emotion> newLstEmotions){
        this.lstEmotions = newLstEmotions;
    }

    public int getNumberOfEmotions(){
        return lstEmotions.size();
    }

    // Task A_1
    // return the number of emotion of the given EmotionType et
    // Remark: No test cases are going to be created.
    public int howGivenManyEmotionTypeInListEmotions(EmotionType et){
        long nJE= lstEmotions.stream().filter(s -> s.getEmotionType().equals(et)).count();
        return (int) nJE;
    }

    // Task A_2
    // return the list of predominant emotions
    // Remark: Create a set of test cases to assess the correctness of your code.
    //         Create a class to test this method, several test cases are needed.
    //         One sample test case is provided in class Test_ListEmotions.
    public List<Emotion> predominantEmotion(){
        List<Emotion> lstEPredominant = new ArrayList<>();
        Map<EmotionType,Long> map = new HashMap<>();

        map.put(EmotionType.Joy, lstEmotions.stream()
                .filter(s->s.getEmotionType().equals(EmotionType.Joy)).count());
        map.put(EmotionType.Anger, lstEmotions.stream()
                .filter(s->s.getEmotionType().equals(EmotionType.Anger)).count());
        map.put(EmotionType.Sadness, lstEmotions.stream()
                .filter(s->s.getEmotionType().equals(EmotionType.Sadness)).count());
        map.put(EmotionType.Disgust, lstEmotions.stream()
                .filter(s->s.getEmotionType().equals(EmotionType.Disgust)).count());
        map.put(EmotionType.Fear, lstEmotions.stream()
                .filter(s->s.getEmotionType().equals(EmotionType.Fear)).count());

        map = map.entrySet().stream()
                .sorted(Map.Entry.comparingByValue(Comparator.reverseOrder()))
                .collect(Collectors.toMap(Map.Entry::getKey, Map.Entry::getValue, (e1, e2) -> e2,
                        LinkedHashMap::new));

        Map.Entry<EmotionType,Long> firstEntry = map.entrySet().iterator().next();

        map = map.entrySet().stream()
                .filter(s->s.getValue().equals(firstEntry.getValue()))
                .collect(Collectors.toMap(Map.Entry::getKey, Map.Entry::getValue));

        map.forEach((key, value)->
            lstEPredominant.addAll(lstEmotions.stream()
                    .filter(f->f.getEmotionType().equals(key)).collect(Collectors.toList()))
        );

        return  lstEPredominant;
    }

    // Task A_3
    // Eliminate the emotions that are of given type EmotionType et
    // Remark: A set of test cases to assess the correctness of your code is provided.
    //         A class to test this method was created, several test cases were added.
    //         Use the test cases to check for your code.
    public void eliminateAllProvidedEmotion(EmotionType et){
        this.lstEmotions = lstEmotions.stream().filter(s -> !s.getEmotionType()
                .equals(et))
                .collect(Collectors.toList());
    }
}
